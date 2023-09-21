#include "monty.h"
/***/
void push(stack_t **stack, unsigned int line_number)
{

	if (arg->tok_number <= 1 || !is_number(arg->tokens[1])) 
		wrong_push(line_number);
	if (((*stack) = malloc(sizeof(stack_t))) == NULL)
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
/***/
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = arg->head;

	(void)(*stack);
	(void)line_number;
	if (!temp)
		return;
	while(temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
