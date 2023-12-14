#include "monty.h"
/**
 * addnodeEnd - adds a new node at the rear of a queue
 * @head: double pointer to queue
 * @n: element to be added
 */
void addnodeEnd(stack_t **head, int n)
{
	stack_t *newnode, *temp = NULL;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newnode->n = n;
	if (*head != NULL)
	{
		temp = *head;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = newnode;
		newnode->prev = temp;
		newnode->next = NULL;
	}
	else
	{
		newnode->prev = NULL;
		newnode->next = NULL;
		*head = newnode;
	}
}
