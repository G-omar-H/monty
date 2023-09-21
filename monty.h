#ifndef MOUNTY_H
#define MOUNTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
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
 * struct argument_t - struct of global variables elements
 * @line: line string regoster
 * @file: file descriptor
 * @line_number: track of the nd line
 * @tok_number: track of the token lenght
 * @stack_len: track of the stack lincked_list leght
 * @token: 2nd dimention array of tokens
 * @op: pointer to instrution struct above
 * @head: pointer to the top stack lincked_list struct
 * Description: struct of global variables.
 */
typedef struct argument_s
{
	char *line;
	FILE *file;
	unsigned int line_number;
	unsigned int tok_number;
	unsigned int stack_len;
	char **tokens;
	instruction_t *op;
	stack_t *head;
} argument_t;

/*Global vribale*/
extern argument_t *arg;

/*error handlers*/
void malloc_fails(void);
void validate_usage(int ac);
void open_fails(char *filename);
void wrong_push(unsigned int line_number);
void invalid_instruction(void);

/*stream handlers*/
void initialize_args(void);
void get_stream(char *filename);
void close_stream(void);

/*opcodes handlers*/
void tokenize_line(void);
void get_instruct(void);
int is_number(char *str);
void execute_opcode(void);

/*operators*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void _div(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);


/*memory delibaters*/
void free_arr_tokens(void);
void free_args(void);
void free_head(void);
void free_stack(stack_t *head);
void free_all_args(void);

#endif /*MOUNTY_H*/
