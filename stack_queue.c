#include "monty.h"
/**
 * stack - switches to stack
 * @head: double pointer to stack
 * @line_no: line number
 */
void stack(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
	global.flag = 0;
}

/**
 * queue - switches to queue
 * @head: double pointer to stack
 * @line_no: line number
 */
void queue(stack_t **head, unsigned int line_no)
{
	(void)head;
	(void)line_no;
	global.flag = 1;
}
