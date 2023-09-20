#include "monty.h"
/**
* free_allstack - frees dll
* @head: param
*/
void free_allstack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
