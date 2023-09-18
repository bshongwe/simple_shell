#ifndef FULL_STACK_H
#define FULL_STACK_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int stack[MAX_STACK_SIZE];
    int top;
} Stack;

#define MAX_CMD_LENGTH 100
#define MAX_TOKENS 10
#define MAX_HISTORY 100

typedef struct {
    char command[MAX_CMD_LENGTH];
    int count;
} CommandEntry;

typedef struct {
    char name[MAX_CMD_LENGTH];
    char value[MAX_CMD_LENGTH];
} Variable;

void initialize_stack(Stack *stack);
int is_empty(Stack *stack);
int is_full(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);

int i;
void print_i();
void print_j();

#endif /* end of FULL_STACK_H file*/
