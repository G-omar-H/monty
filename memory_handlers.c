#include "monty.h"
/**
 * initialize_args - do initialize global argument pointer struct elements
 *
 * Return: void.
 */
void initialize_args(void)
{

	arg = (argument_t *)malloc(sizeof(argument_t));
	if (arg == NULL)
		malloc_fails();
	arg->op = (instruction_t *)malloc(sizeof(instruction_t));
	if (arg->op == NULL)
		malloc_fails();
	arg->head = NULL;
	arg->tail = NULL;
	arg->line = NULL;
	arg->file = NULL;
	arg->line_number = 0;
	arg->tok_number = 0;
	arg->stack_len = 0;
	arg->mode = 0;
}
/**
 * free_arr_tokens - frees a 2nd dimnsion array
 *
 * Return: void
 */
void free_arr_tokens(void)
{
	int i = 0;

	if (arg->tokens == NULL)
		return;
	while (arg->tokens[i] != NULL)
	{
		free(arg->tokens[i]);
		i++;
	}
	free(arg->tokens);
	arg->tokens = NULL;
}
/**
 * free_args - frees global variale pointer struct elements
 *
 * Return: void.
 */
void free_args(void)
{
	if (arg == NULL)
		return;
	if (arg->op != NULL)
	{
		free(arg->op);
		arg->op = NULL;
	}
	free_head();
	if (arg->line != NULL)
	{
		free(arg->line);
		arg->line = NULL;
	}
	free(arg);
	arg = NULL;
}
/**
 * free_head - frees top lincked list stack node
 *
 * Return: void
 */
void free_head(void)
{
	if (arg->head != NULL)
		free_stack(arg->head);
	arg->head = NULL;
}

/**
 * free_stack - frees a lincked list stack
 * @head: pointer to the top node
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;
	while (node->next)
	{
		head = node->next;
		free(node);
	head->prev = NULL;
		node  = head;
	}
	free(node);

}
