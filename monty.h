#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#define OPCODES\
	{					\
		{"push", push},			\
		{"pall", pall},			\
		{"pint", pint},			\
		{"pop", pop},			\
		{"swap", swap},			\
		{"add", add},			\
		{"nop", nop},			\
		{NULL, NULL}			\
	}

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct arg_s - holds value of argument
 * @argument: the argument
 *
 * Description: struct to hold monty argument
 */

typedef struct arg_s
{
        char *argument;
} arg_t;

arg_t arg;

/* function(ality) */
void run_opcode(char *opcode, stack_t **stack, unsigned int line_number);
void free_stack(stack_t **stack);

/* opcodes for monty reader */
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/* error-printing functions */
void file_error(char *file);
void usage_error(void);
void push_error(unsigned int line_number);
void pint_error(unsigned int line_number);
void pop_error(unsigned int line_number);


#endif /* MONTY_H */
