#include "monty.h"
/**
 * nd_swap - fnction add the top two elements to stack.
 * @head: param
 * @character_counter: param
 * Return: nothing
*/
void nd_swap(stack_t **head, unsigned int character_counter)
{
	stack_t *h;
	int i = 0, ax_node;

	h = *head;
	while (h)
	{
		h = h->next;
		i++;
	}
	if (i < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax_node = h->n;
	h->n = h->next->n;
	h->next->n = ax_node;
}

/**
 * nd_adv_pstr - function print str from top
 * @head: param
 * @character_counter: param
 * Return: nothing
*/
void nd_adv_pstr(stack_t **head, unsigned int character_counter)
{
	stack_t *h;
	(void)character_counter;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
