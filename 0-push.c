#include "monty.h"

/**
 * nd_push - function add node to the stack
 * @head: param
 * @character_counter: param
 *
 * Return: nothing
 */
void nd_push(stack_t **head, unsigned int character_counter)
{
	int i;
	int j = 0;
	int fg = 0;

	if (mon.arg_count)
	{
		if (mon.arg_count[0] == '-')
			j++;
		for (; mon.arg_count[j] != '\0'; j++)
		{
			if (mon.arg_count[j] > 57 || mon.arg_count[j] < 48)
				fg = 2; }
		if (fg == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", character_counter);
			fclose(mon.file_content);
			free(mon.character_content);
			free_allstack(*head);
			exit(EXIT_FAILURE); }}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", character_counter);
		fclose(mon.file_content);
		free(mon.character_content);
		free_allstack(*head);
		exit(EXIT_FAILURE); }
	i = atoi(mon.arg_count);
	if (mon.j == 0)
		ad_node_tohead(head, i);
	else
		add_node_to_queue(head, i);
}
