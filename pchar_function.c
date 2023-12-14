#include "monty.h"
/**
 * pchar - prints the char at the top of the stack
 * @head: double pointer to stack
 * @line_no: line number
 */
void pchar(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;

	tmp = *head;
	if (tmp)
	{
		if (tmp->n < 0 || tmp->n > 127)
		{
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_no);
			fclose(global.file);
			free(global.line_content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
		else
			printf("%c\n", (char)tmp->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
}
