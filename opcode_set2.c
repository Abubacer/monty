#include "monty.h"

/**
 * pchar_opcode - an opcode that prints the char at the top of the stack,
 * followed by a new line.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void pchar_opcode(stack_t **stack, unsigned int line_number)
{
	int int_top;

	int_top = (*stack)->n;

	if (*stack == NULL)
	{
		fprintf(stderr, PCHAR_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	if (int_top < 0 || int_top > 127)
	{
		fprintf(stderr, OUTRANGE_ERROR, line_number);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", int_top);
}

/**
 * pstr_opcode - an opcode that prints the string starting at the top of
 * the stack, followed by a new line.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void pstr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node;

	current_node = *stack;

	while (current_node != NULL && current_node->n == 0
		&& current_node->n >= 0 && current_node->n <= 127)
	{
		if (current_node->n == 32 ||
		(current_node->n >= 65 && current_node->n <= 90) ||
		(current_node->n >= 97 && current_node->n <= 122))
		{
			printf("%c", current_node->n);
		}
		else
		{
			break;
		}

		current_node = current_node->next;
	}

	printf("\n");
	(void)line_number;
}
/**
 * rotl_opcode - an opcode that rotates the stack to the top.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void rotl_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second_top;

	if (*stack != NULL && (*stack)->next != NULL)
	{
		top = *stack;
		second_top = (*stack)->next;

		while (top->next != NULL)
			top = top->next;

		top->next = *stack;
		(*stack)->prev = top;
		(*stack)->next = NULL;

		*stack = second_top;
		second_top->prev = NULL;
	}
	(void)line_number;
}
/**
 * rotr_opcode - an opcode that rotates the stack to the bottom.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void rotr_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *top;

	if (*stack == NULL && (*stack)->next != NULL)
	{
		top = *stack;

		while (top->next != NULL)
			top = top->next;

		top->next = *stack;
		(*stack)->prev = top;
		*stack = top->prev;
		(*stack)->next = NULL;
		top->prev = NULL;
	}
	(void)line_number;
}

