#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 256
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - variables
 * @arg: value inputed by user
 * @line_content: line content
 * @file: pointer to monty file
 * @flag: flag change for stack and queue
 */
typedef struct global_s
{
	char *arg;
	char *line_content;
	FILE *file;
	int flag;
} global_t;
extern global_t global;

void addnode(stack_t **head, int n);
void push(stack_t **head, unsigned int line_no);
void pall(stack_t **head, unsigned int line_no);
void pint(stack_t **head, unsigned int line_no);
void swap(stack_t **head, unsigned int line_no);
void pop(stack_t **head, unsigned int line_no);
void add(stack_t **head, unsigned int line_no);
void nop(stack_t **head, unsigned int line_no);
void sub(stack_t **head, unsigned int line_no);
void add(stack_t **head, unsigned int line_no);
void _div(stack_t **head, unsigned int line_no);
void mul(stack_t **head, unsigned int line_no);
void mod(stack_t **head, unsigned int line_no);
void pchar(stack_t **head, unsigned int line_no);
void pstr(stack_t **head, unsigned int line_no);
void rotl(stack_t **head, unsigned int line_no);
void rotr(stack_t **head, unsigned int line_no);
void _stack(stack_t **head, unsigned int line_no);
void queue(stack_t **head, unsigned int line_no);
void addnodeEnd(stack_t **head, int n);
int exec(char *content, stack_t **stack, unsigned int count, FILE *monty_file);
void free_stack(stack_t *head);

#endif
