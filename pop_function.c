#include "monty.h"
/**
 * pop - remove top(head) element of the stack
 * @head: double pointer to the stack
 * @line_no: line number
 */
void pop(stack_t **head, unsigned int line_no)
{
	stack_t temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	head = head->next;
	free(temp)
}
