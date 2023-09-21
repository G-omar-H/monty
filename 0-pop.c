#include "monty.h"
/**
 * nd_pop - prints the top
 * @head: param
 * @character_counter: param
 * Return: nothing
*/
void nd_pop(stack_t **head, unsigned int character_counter)
{
	stack_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}

/**
  *nd_sub - function node sub
  *@head: param
  *@character_counter: param
  *Return: nothing
 */
void nd_sub(stack_t **head, unsigned int character_counter)
{
	stack_t *ax_node;
	int i, j;

	ax_node = *head;
	for (j = 0; ax_node != NULL; j++)
		ax_node = ax_node->next;
	if (j < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE);
	}
	ax_node = *head;
	i = ax_node->next->n - ax_node->n;
	ax_node->next->n = i;
	*head = ax_node->next;
	free(ax_node);
}
