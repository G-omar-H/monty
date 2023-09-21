#include "monty.h"
/**
 * nd_pint - prints the top
 * @head: param
 * @character_counter: param
 * Return: nothing
*/
void nd_pint(stack_t **head, unsigned int character_counter)
{

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
