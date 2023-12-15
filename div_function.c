#include "monty.h"
/**
 * _div - divides the second top element by the top element of the stack.
 * @head: double pointer to head
 * @line_no: line number
 */
void _div(stack_t **head, unsigned int line_no)
{
	stack_t *tmp;
	int count = 0, result;

	tmp = *head;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	if (count < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	if (tmp->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_no);
		fclose(global.file);
		free(global.line_content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = tmp->next->n / tmp->n;
	tmp->next->n = result;
	*head = tmp->next;
	free(tmp);
}
