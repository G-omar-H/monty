#include "monty.h"
/**
 * get_instruct - validate instruction from opcode
 *
 * Return: void.
 */
void get_instruct(void)
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", &push}, {"pall", &pall},
		{"pint", &pint}, {"pop", &pop},
		{"swap", &swap}, {"add", &add},
		{"nop", &nop}, {"sub", &sub},
		{"div", &_div}, {"mul", &mul},
		{"mod", &mod}, {"pchar", &pchar},
		{"pstr", &pstr}, {"rotl", &rotl},
		{NULL, NULL}
	};
	if (arg->tok_number == 0)
		return;
	for (; instruction[i].opcode != NULL; i++)
	{
		if (strcmp(instruction[i].opcode, arg->tokens[0]) == 0)
		{
			arg->op->opcode = instruction[i].opcode;
			arg->op->f = instruction[i].f;
			return;
		}
	}
	invalid_instruction();
}

/**
 * execute_opcode - run the opcode instruction
 *
 * Return: void.
 */
void execute_opcode(void)
{
	stack_t *stack = NULL;

	if (arg->tok_number == 0)
		return;
	arg->op->f(&stack, arg->line_number);
}

/**
 * is_number - check if a string is a number
 * @str: sring to check
 * Return: void.
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		else if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
