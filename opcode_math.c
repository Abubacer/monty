#include "monty.h"

/**
 * sub_opcode - an opcode that subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void sub_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, SUB_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	pop_opcode(stack, line_number);
}

/**
 * div_opcode - an opcode that divides the second top element of the stac
 * by the top element of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void div_opcode(stack_t **stack, unsigned int line_number)
{

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, DIV_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, DIV_ZERO_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	pop_opcode(stack, line_number);
}
/**
 * mul_opcode - an opcode that multiplies the second top element of the
 * stack with the top element of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void mul_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, MUL_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	pop_opcode(stack, line_number);
}
/**
 * mod_opcode - an opcode that computes the rest of the division of
 * the second top element of the stack by the top element of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void mod_opcode(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, MOD_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, DIV_ZERO_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	pop_opcode(stack, line_number);
}
