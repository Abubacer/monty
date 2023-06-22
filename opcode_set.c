#include "monty.h"

/**
 * pint_opcode - an opcode that prints the value at the top of the stack,
 * followed by a new line.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void pint_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, PINT_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * pop_opcode - an opcode that removes the top element of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void pop_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (*stack == NULL || stack == NULL)
	{
		fprintf(stderr, POP_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	*stack = (*stack)->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;

	free(temp);
}

/**
 * swap_opcode - an opcode that swaps the top two elements of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void swap_opcode(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, SWAP_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

/**
 * add_opcode - an opcode that adds the top two elements of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void add_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, ADD_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop_opcode(stack, line_number);
}

/**
 * nop_opcode - an opcode that doesn’t do anything,
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void nop_opcode(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
