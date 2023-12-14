#include "lists.h"
/**
 *pall - prints all the elements of a stack.
 *@head: pointer to data
 *@line_no: line number
 */
void pall(stack_t **head, unsigned int line_no)
{
	stack_ *temp;
	(void)line_no;

	temp = *head;
	if (temp  == NULL)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
