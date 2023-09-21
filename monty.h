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
 * struct argument_t - struct of global variables 
 * 
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
void malloc_fails();
void validate_usage(int ac);
void open_fails(char *filename);
void wrong_push(unsigned int line_number);
void invalid_instruction();

/*stream handlers*/
void initialize_args();
void get_stream(char *filename);
void close_stream();

/*opcodes handlers*/
void tokenize_line();
void get_instruct();
int is_number(char *str);
void execute_opcode();

/*operators*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);

/*memory delibaters*/
void free_arr_tokens();
void free_args();
void free_head();
void free_stack(stack_t *head);
void free_all_args();

#endif /*MOUNTY_H*/
