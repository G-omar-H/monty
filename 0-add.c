#include "monty.h"
/**
 * nd_add - function add the top two ele to stack
 * @head: param
 * @character_counter: param
 * Return: nothing
*/
void nd_add(stack_t **head, unsigned int character_counter)
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
		fprintf(stderr, "L%d: can't add, stack too short\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	ax_node = h->n + h->next->n;
	h->next->n = ax_node;
	*head = h->next;
	free(h);
}

/**
  *nd_nop- function doing nothing
  *@head: param
  *@character_counter: param
  *Return: nothing
 */
void nd_nop(stack_t **head, unsigned int character_counter)
{
	(void) head;
	(void) character_counter;
}
