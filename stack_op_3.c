#include "monty.h"
#include <stdio.h>
/**
 * nop - continue.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	return;
}
/**
 * pchar - prints the character value of the the top of a stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	(void)(*stack);
	if (!arg->head)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	else if (!isascii(arg->head->n))
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", arg->head->n);
}
/**
 * pstr - prints the string value of the stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void pstr(stack_t **stack, unsigned int line_number)
{

	(void)line_number;
	(*stack) = arg->head;
	if (!arg->head)
	{
		printf("\n");
		return;
	}
	while ((*stack) && (*stack)->n != 0 && isascii((*stack)->n))
	{
		printf("%c", (*stack)->n);
		(*stack) = (*stack)->next;
	}
	printf("\n");
}
/**
 * rotl - prints the character value of the the top of a stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *tail = NULL;

	(void)line_number;
	if (arg->stack_len < 2)
		return;
	(*stack) = arg->head;
	tail = (*stack)->next;
	arg->head = tail;
	while ((*stack))
	{
		if (!tail->next)
		{

			tail->next = (*stack);
			(*stack)->next = NULL;
			(*stack)->prev = tail;
			break;
		}
		tail = tail->next;
	}
}
