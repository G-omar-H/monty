#include "monty.h"

/**
 * ad_node_tohead - function add node to head
 * @head: param
 * @n: param
 * Return: nothing
 */
void ad_node_tohead(stack_t **head, int n)
{
	stack_t *new_node, *ax_node;

	ax_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (ax_node)
		ax_node->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * tof_que - function print the top
 * @head: param
 * @character_counter: param
 * Return: nothing
 */
void tof_que(stack_t **head, unsigned int character_counter)
{
	(void)head;
	(void)character_counter;
	mon.j = 1;
}

/**
 * add_node_to_queue - func add node to tail
 * @head: param
 * @n: param
 * Return: nothing
 */
void add_node_to_queue(stack_t **head, int n)
{
	stack_t *new_node, *ax_node;

	ax_node = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (ax_node)
	{
		while (ax_node->next)
			ax_node = ax_node->next;
	}
	if (!ax_node)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		ax_node->next = new_node;
		new_node->prev = ax_node;
	}
}
