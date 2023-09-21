#include "monty.h"
/**
 * push - push a value to a lincked list stack
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
*/
void push(stack_t **stack, unsigned int line_number)
{

	if (arg->tok_number <= 1 || !is_number(arg->tokens[1]))
		wrong_push(line_number);
	(*stack) = malloc(sizeof(stack_t));
	if ((*stack) == NULL)
		malloc_fails();
	(*stack)->n = (int) atoi(arg->tokens[1]);
	(*stack)->next = (*stack)->prev = NULL;
	if (arg->head)
	{
		(*stack)->next = arg->head;
		arg->head->prev = (*stack);
	}
	arg->head = (*stack);
	arg->stack_len += 1;
}
/**
 * pall - displays a lincked list stack
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
*/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = arg->head;

	(void)(*stack);
	(void)line_number;
	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
