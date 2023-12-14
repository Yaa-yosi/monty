#include "monty.h"
/**
 * pstr - prints the string starting at the top of the stack
 * @head: double pointer to stack
 * @line_no: line number
 */
void pstr(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	(void)line_no;

	tmp = *head;
	while (tmp)
	{
		if (tmp->n == 0)
			break;
		else if (tmp->n < 0 || tmp->n > 127)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
