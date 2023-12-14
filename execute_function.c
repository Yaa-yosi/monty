#include "monty.h"
/**
 * exec - executes the opcode
 * @stack: head linked list - stack
 * @count: line_counter
 * @monty_file: poiner to monty file
 * @content: line content
 * Return: no return
 */
int exec(char *content, stack_t **stack, unsigned int count, FILE *monty_file)
{
	instruction_t func[] = {
		{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub},
		{"div", _div}, {"mul", mul},
		{"mod", mod}, {"pchar", pchar},
		{"pstr", pstr}, {"rotl", rotl},
		{"rotr", rotr}, {"queue", queue},
		{"stack", _stack}, {NULL, NULL}
	};
	unsigned int idx = 0;
	char *ops;

	ops = strtok(content, " \n\t");
	if (ops && ops[0] == '#')
		return (0);
	global.arg = strtok(NULL, " \n\t");
	while (func[idx].opcode && ops)
	{
		if (strcmp(ops, func[idx].opcode) == 0)
		{	func[idx].f(stack, count);
			return (0);
		}
		idx++;
	}
	if (ops && func[idx].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", count, ops);
		fclose(monty_file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
