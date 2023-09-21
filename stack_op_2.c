#include "monty.h"
/**
 * add - merge the top two nodes.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void add(stack_t **stack, unsigned int line_number)
{
	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	(*stack)->n += arg->head->n;
	free(arg->head);
	arg->head = (*stack);
}
/**
 * sub - perform substraction operation for the two tops on the stack
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	(*stack)->n -= arg->head->n;
	free(arg->head);
	arg->head = (*stack);
}
/**
 * _div - perform division operation for the two tops on the stack
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void _div(stack_t **stack, unsigned int line_number)
{
	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	else if (arg->head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	(*stack)->n /= arg->head->n;
	free(arg->head);
	arg->head = (*stack);
}
/**
 * mul - perform multiplication operation for the two tops on the stack
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	(*stack)->n *= arg->head->n;
	free(arg->head);
	arg->head = (*stack);
}
/**
 * mod - perform moduler operation for the two tops on the stack.
 * @stack: top stack tracker
 * @line_number: line number track
 * Return: void.
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (arg->stack_len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	else if (arg->head->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	(*stack) = arg->head->next;
	(*stack)->n %= arg->head->n;
	free(arg->head);
	arg->head = (*stack);
}
