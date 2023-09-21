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
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
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
/**
 * pint - print the value at the top of a stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	if (!arg->head)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", arg->head->n);
}
/**
 * pop - remove the value at the top of a stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	(*stack) = arg->head;
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	arg->head = (*stack)->next;
	free(*stack);
	arg->stack_len -= 1;
}
/**
 * swap - switch values between top two nodes.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int hold = 0;

	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	hold = arg->head->n;
	arg->head->n = (*stack)->n;
	(*stack)->n = hold;
}
