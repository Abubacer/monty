#include "monty.h"

/**
 * free_stack - a function that frees the memory allocated
 * to the doubly linked list.
 * @stack: the pointer to the first node of the list.
 *
 * Return: void.
 */

void free_stack(stack_t *stack)
{
	stack_t *temp;

	while (stack != NULL)
	{
		temp = stack;
		stack = stack->next;
		free(temp);
	}
}
