#include "monty.h"
/**
 * push - add a node to the top of a stack
 * @head: head of the stack
 * @line_no: line number
 */
void push(stack_t **head, unsigned int line_no)
{
	int num, index = 0;

	if (global.arg)
	{
		if (global.arg[0] == '-')
			index++;
		for (; global.arg[index] != '\0'; index++)
		{
			if (global.arg[index] > 57 || global.arg[index] < 48)
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_no);
				fclose(global.file);
				free(global.line_content);
				free_stack(*head);
				exit(EXIT_FAILURE);
			}
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(global.arg);
	addnode(head, num);
}
