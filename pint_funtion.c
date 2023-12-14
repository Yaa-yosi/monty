#include "monty.h"
/**
 *pint - prints the top value of a list
 *@head:  double pointer to head
 *@line_no: line number
 */
void pint(stack_t **head, unsigned int line_no)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pint\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}


