#include "monty.h"

/**
 * main - entry point.
 * @argc: the argument count.
 * @argv: the argument vector.
 *
 * Return: 0 on success.
 */

int main(int argc, char **argv)
{
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, USAGE_ERROR);
		exit(EXIT_FAILURE);
	}

	f_read(argv[1], &stack);
	free_stack(stack);

	return (0);
}

/**
 * f_read - a function that reads a bytcode file.
 * @filename: the path name to file.
 * @stack: a pointer to the top of the stack.
 *
 * Return: void.
 */

void f_read(char *filename, stack_t **stack)
{
	FILE *monty_file = fopen(filename, "r");
	char *opCode, line[MAX_LENGTH];
	unsigned int current_line = 1;

	if (monty_file == NULL)
	{
		fprintf(stderr, OPEN_ERROR, filename);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), monty_file) != NULL)
	{
		opCode = line_parser(line);
		if (opCode != NULL && opCode[0] != '#')
		{
			instruct_func s = get_opcode_func(opCode);
		if (s == NULL)
		{
			fprintf(stderr, INST_ERROR, current_line, opCode);
			exit(EXIT_FAILURE);
		}
			s(stack, current_line);
		}
		current_line++;
	}

	fclose(monty_file);
}
/**
 * line_parser - a function that parses the line to extract the opcode
 * and arguments and returns the opcode.
 * @line: the line of monty code to tokenize.
 *
 * Return: the opcode or NULL on failure.
 */

char *line_parser(char *line)
{
	char *opCode;

	opCode = strtok(line, " \t\n");

	if (opCode == NULL)
		return (NULL);

	return (opCode);
}

/**
 * get_opcode_func - a function that determines the corresponding function
 * for a given opcode returns the associated function.
 * @str: the opcode to compare.
 *
 * Return: the opcode associated function or NULL on failure.
 */

instruct_func get_opcode_func(char *str)
{
	int idx = 0;
	instruction_t instr_set[] = {
		{"push", push_opcode},
		{"pall", pall_opcode},
		{"pint", pint_opcode},
		{"pop", pop_opcode},
		{"swap", swap_opcode},
		{"add", add_opcode},
		{"nop", nop_opcode},
		{"sub", sub_opcode},
		{"div", div_opcode},
		{"mul", mul_opcode},
		{"mod", mod_opcode},
		{"pchar", pchar_opcode},
		{"pstr", pstr_opcode},
		{"rotl", rotl_opcode},
		{"rotr", rotr_opcode},
		{NULL, NULL},
	};

	while (instr_set[idx].opcode != 0 &&
		strcmp(instr_set[idx].opcode, str) != 0)
	{
		idx++;
	}

	return (instr_set[idx].f);
}

/**
 * is_int - a function that checks if a string is a number.
 * @str: the string to check.
 *
 * Return: 1 if it is a number or 0 if it is not.
 */

int is_int(char *str)
{
	unsigned int i;

	if (str == NULL)
		return (0);

	for (i = 0 ; str[i] ; i++)
	{
		if (i == 0 && str[0] == '-')
			continue;

		if (!isdigit(str[i]))
			return (0);
	}

	return (1);
}

