#include "monty.h"
/**
 * addnode - adds a new node at the beginning of doubly linked list
 * @head: Double head pointer
 * @n: element to be added to stack
 */
void stack_t addnode(stack_t **head, int n)
{
	stack_t *newnode;

	newnode = malloc(sizeof(stack_t));
	if (!newnode)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (*head != NULL)
		(*head)->prev = newnode;
	newnode->n = n;
	newnode->prev = NULL;
	newnode->next = *head;
	*head = new_node;
}
