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
