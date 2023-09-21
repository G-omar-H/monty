#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

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
 */
typedef struct mon_s
{
	char *arg_count;
	FILE *file_content;
	char *character_content;
	int j;
} mon_t;
extern mon_t mon;
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

int execute(char *character_content, stack_t **stack, unsigned int character_counter, FILE *file_cont);
void pall_stc(stack_t **head, unsigned int char_counter);
void nd_push(stack_t **head, unsigned int character_counter);
void nd_pint(stack_t **head, unsigned int character_counter);
void nd_pop(stack_t **head, unsigned int character_counter);
void nd_swap(stack_t **head, unsigned int character_counter);
void nd_add(stack_t **head, unsigned int character_counter);
void nd_nop(stack_t **head, unsigned int character_counter);
void free_allstack(stack_t *head);

void nd_sub(stack_t **head, unsigned int character_counter);
void nd_adv_pstr(stack_t **head, unsigned int character_counter);
void ad_node_tohead(stack_t **head, int n);
void tof_que(stack_t **head, unsigned int character_counter);
void add_node_to_queue(stack_t **head, int n);
#endif /*monty.h*/
