#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 128

#define USAGE_ERROR "USAGE: monty file\n"
#define OPEN_ERROR "Error: Can't open file %s\n"
#define INST_ERROR "L%d: unknown instruction %s\n"
#define PUSH_ERROR "L%d: usage: push integer\n"
#define PINT_ERROR "L%d: can't pint, stack empty\n"
#define SWAP_ERROR "L%d: can't swap, stack too short\n"
#define POP_ERROR  "L%d: can't pop an empty stack\n"
#define ADD_ERROR "L%d: can't add, stack too short\n"

/**
 * struct stack_s - doubly linked list representation of a stack(or queue)
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

typedef void (*instruct_func)(stack_t **stack, unsigned int line_number);

void f_read(char *filename, stack_t **stack);
char *line_parser(char *line);
instruct_func get_opcode_func(char *str);
int is_int(char *str);

void push_opcode(stack_t **stack, unsigned int line_number);
void pall_opcode(stack_t **stack, unsigned int line_number);
void pint_opcode(stack_t **stack, unsigned int line_number);
void pop_opcode(stack_t **stack, unsigned int line_number);
void swap_opcode(stack_t **stack, unsigned int line_number);
void add_opcode(stack_t **stack, unsigned int line_number);
void nop_opcode(stack_t **stack, unsigned int line_number);

void free_stack(stack_t *stack);

#endif
