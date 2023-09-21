#include "monty.h"
/***/
void get_instruct()
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", &push}, {"pall", &pall},
		{NULL, NULL}
	};
	if (arg->tok_number == 0)
		return;
	for (;instruction[i].opcode != NULL; i++)
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

/***/
void execute_opcode()
{
	stack_t *stack = NULL;

	if (arg->tok_number == 0)
		return;
	arg->op->f(&stack, arg->line_number);
}

/***/
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
