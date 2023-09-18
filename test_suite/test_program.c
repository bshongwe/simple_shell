#include "full_stack.h"


CommandEntry command_history[MAX_HISTORY];
Variable variables[MAX_TOKENS];
int num_variables = 0;
int history_count = 0;

void execute_command(char *command) {
    char *args[MAX_TOKENS];
    int i = 0;
    int j = 10;

    // Tokenize the command
    char *token = strtok(command, " \t\n");
    while (token != NULL && i < MAX_TOKENS - 1) {
        args[i++] = token;
        token = strtok(NULL, " \t\n");
    }
    args[i] = NULL;

    // Check for variable assignments
    for (int j = 0; j < i; j++) {
        char *equal_sign = strchr(args[j], '=');
        if (equal_sign != NULL) {
            strncpy(variables[num_variables].name, args[j], equal_sign - args[j]);
            variables[num_variables].name[equal_sign - args[j]] = '\0';
            strcpy(variables[num_variables].value, equal_sign + 1);
            num_variables++;
            args[j] = NULL;
        }
    }

    // Execute the command
    if (execvp(args[0], args) == -1) {
        perror("Error");
        exit(EXIT_FAILURE);
    }
}

void add_command_to_history(char *command) {
    if (history_count >= MAX_HISTORY) {
        for (int i = 1; i < MAX_HISTORY; i++) {
            strcpy(command_history[i - 1].command, command_history[i].command);
            command_history[i - 1].count = command_history[i].count;
        }
        history_count = MAX_HISTORY - 1;
    } else {
        history_count++;
    }
    strcpy(command_history[history_count - 1].command, command);
    command_history[history_count - 1].count = 1;
}

void display_command_history() {
    for (int i = 0; i < history_count; i++) {
        printf("%d %s\n", command_history[i].count, command_history[i].command);
    }
}

int get_command_from_history(int count, char *command) {
    for (int i = 0; i < history_count; i++) {
        if (command_history[i].count == count) {
            strcpy(command, command_history[i].command);
            return 1;
        }
    }
    return 0;
}

void update_command_history_count(int count) {
    for (int i = 0; i < history_count; i++) {
        if (command_history[i].count == count) {
            command_history[i].count++;
            return;
        }
    }
}

void complete_command(char *command_prefix, char *completed_command) {
    strcpy(completed_command, command_prefix);
    for (int i = 0; i < num_variables; i++) {
        if (strncmp(variables[i].name, command_prefix, strlen(command_prefix)) == 0) {
            strcat(completed_command, variables[i].name + strlen(command_prefix));
            return;
        }
    }
}

void print_i() {
    printf("Value of i: %d\n", i);
}

void print_j() {
    printf("Value of j: %d\n", j);
}

int main() {
    char command[MAX_CMD_LENGTH];
    char *prompt = "hsh> ";
    int prompt_length = strlen(prompt);

    int write_status;
    ssize_t read_status;
    int j = 0;
    int l;

    while (1) {
        write_status = write(STDOUT_FILENO, prompt, prompt_length);
        if (write_status == -1) {
            perror("Error");
            exit(EXIT_FAILURE);
        }

        read_status = read(STDIN_FILENO, command, sizeof(command) - 1);
        if (read_status < 0) {
            perror("Error");
            exit(EXIT_FAILURE);
        } else if (read_status == 0) {
            write(STDOUT_FILENO, "\n", 1);
            break;
        }

        // Null-terminate the command
        command[read_status - 1] = '\0';

        // Exit if the command is "exit"
        if (strcmp(command, "exit") == 0) {
            break;
        }

        // Add the command to the history
        add_command_to_history(command);

        // Handle command history recall
        if (command[0] == '!') {
            int count = atoi(command + 1);
            if (count == 0) {
                if (command[1] == '!') {
                    if (history_count > 0) {
                        get_command_from_history(history_count, command);
                    } else {
                        continue;
                    }
                } else {
                    continue;
                }
            } else {
                if (!get_command_from_history(count, command)) {
                    continue;
                }
            }
            update_command_history_count(count);
        }

        // Handle command completion
        if (command[0] == '\t') {
            char completed_command[MAX_CMD_LENGTH];
            complete_command("", completed_command);
            strcpy(command, completed_command);
        }

        // Fork the process
        pid_t pid = fork();

        if (pid < 0) {
            perror("Error");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            char expanded_command[MAX_CMD_LENGTH];
            expanded_command[0] = '\0';

            // Handle variable expansion
            int j = 0;
            for (int i = 0; command[i] != '\0'; i++) {
                if (command[i] == '$') {
                    i++;
                    if (command[i] == '\0') {
                        break;
                    }
                    char variable_name[MAX_CMD_LENGTH];
                    int k = 0;
                    while (command[i] != '\0' && command[i] != ' ' && command[i] != '\t') {
                        variable_name[k++] = command[i++];
                    }
                    variable_name[k] = '\0';
                    int variable_found = 0;
                    for (int l = 0; l < num_variables; l++) {
                        if (strcmp(variables[l].name, variable_name) == 0) {
                            strcat(expanded_command, variables[l].value);
                            j += strlen(variables[l].value);
                            variable_found = 1;
                            break;
                        }
                    }
                    if (!variable_found) {
                        i -= k;
                        expanded_command[j++] = '$';
                    }
                } else {
                    expanded_command[j++] = command[i];
                }
            }
            expanded_command[j] = '\0';

            execute_command(expanded_command);
            exit(EXIT_SUCCESS);
        } else {
            // Wait for the child process to complete
            int status;
            waitpid(pid, &status, 0);
            if (status != 0) {
                if (WIFEXITED(status)) {
                    printf("Child process exited with non-zero status %d\n", WEXITSTATUS(status));
                } else if (WIFSIGNALED(status)) {
                    printf("Child process terminated by signal %d\n", WTERMSIG(status));
                }
            }
        }
    }

    return 0;
}
