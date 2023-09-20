#include "monty.h"
/**
 * pall_stc - function pall
 * @head: param
 * @char_counter: param
 *
 * Return: nothing
 */

void pall_stc(stack_t **head, unsigned int char_counter)
{
	stack_t *h;
	(void)char_counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
