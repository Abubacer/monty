#include "monty.h"

/**
 * push_opcode - an opcode that pushes an element to the stack.
 * @stack: the pointer to list
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void push_opcode(stack_t **stack, unsigned int line_number)
{
	char *opcode_arg;
	stack_t *new_node;

	opcode_arg = strtok(NULL, " \t\n");

	if (opcode_arg == NULL || !is_int(opcode_arg))
	{
		fprintf(stderr, PUSH_ERROR, line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(opcode_arg);
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new_node;

	*stack = new_node;
}

/**
 * pall_opcode - an opcode that prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: the pointer to list stack
 * @line_number: the opcode line number
 *
 * Return: void.
 */

void pall_opcode(stack_t **stack, unsigned int line_number)
{
	stack_t *current_node = *stack;

	while (current_node != NULL)
	{
		printf("%d\n", current_node->n);
		current_node = current_node->next;
	}

	(void)line_number;
}
