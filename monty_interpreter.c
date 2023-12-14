#include "monty.h"
global_t global = {NULL, NULL, NULL, 0};
/**
 * main - monty code interpreter
 * @argc: arguement count
 * @argv: monty file name or location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *content = NULL;
	FILE *monty_file;
	size_t size = 1024;
	stack_t *stack = NULL;
	unsigned int count = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		content = malloc(size);
		if (!content)
		{
			fprintf(stderr, "Error: Memory allocation failed\n");
			exit(EXIT_FAILURE);
		}
		if (fgets(content, size, monty_file) == NULL)
		{
			free(content);
			/*break;*/
			fprintf(stderr, "Error: fgets failed\n");
			exit(EXIT_FAILURE);
		}
		global.line_content = content;
		count++;
		exec(content, &stack, count, monty_file);
		free(content);
	}
	free_stack(stack);
	fclose(monty_file);
	return (0);
}
