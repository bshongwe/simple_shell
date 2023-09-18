# Simple Shell Test Suite

The programme defines two structures: CommandEntry and Variable.
These structures are used to store information about commands and variables, respectively.

The main() function is the entry point of the program. It starts by initializing the global variables. Then, it enters a loop where it prompts the user for a command, executes the command, and adds the command to the history. The loop exits when the user enters the "exit" command.

The program then declares a number of global variables, including:
##### command_history: An array of CommandEntry structures that stores the command history.

##### variables: An array of Variable structures that stores the defined variables.

##### num_variables: The number of defined variables.

##### history_count: The number of items in the command history.

The program then defines a few functions:

##### execute_command(): This function executes a given command.
##### add_command_to_history(): This function adds a given command to the command history.
##### display_command_history(): This function displays the command history.
##### get_command_from_history(): This function retrieves a given command from the command history.
##### update_command_history_count(): This function updates the count of a given command in the command history.
##### complete_command(): This function completes a given command prefix.

## Additional Suggestions that may be added that we did not add

Note that these tests do not cover all possible tests, only the basic ones...
##### 1. Add a help command to display a list of all available commands and their descriptions:

void display_help(int fd) {
    char help_message[200];
    sprintf(help_message, "Available commands:\nhelp\t\tDisplay this help message.\nexit\t\tExit the shell.\n");
    write(fd, help_message, strlen(help_message));
}



##### 2. Add error checking to ensure the user has entered a valid command before attempting to execute it:

/* Before forking the process:
 * Check if the command is empty
 */

if (strlen(command) == 0) {
    continue;
}

/* After forking the process, before waiting:
 * Check if execvp failed
 */

if (!executed) {
    char error_message[100];
    sprintf(error_message, "Invalid command: %s\n", command);
    write(STDOUT_FILENO, error_message, strlen(error_message));
    exit(EXIT_FAILURE);
}


# Copmilation:
Compile and run the updated code using the following steps:

1. <code>$ gcc -o hsh shell.c</code>
<code>$ ./hsh</code>
<code>hsh> ls</code>
...

2. <code>hsh> echo $HOME</code>
<code>/home/user</code>

3. <code>hsh> ALIAS="ls -l"</code>
<code>hsh> $ALIAS</code>
...

4. <code>hsh> !3</code>
<code>echo $HOME</code>
<code>/home/user</code>
<code>hsh> TAB<tab></code>
<code>hsh> echo $HOME</code>
<code>/home/user</code>
