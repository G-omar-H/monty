#include "monty.h"

/**
 * execute - function using to ececute opcode
 * @character_content: param
 * @stack: param
 * @character_counter: param
 * @file_cont: param
 *
 * Return: nothing
 */
int execute(char *character_content, stack_t **stack,
		unsigned int character_counter, FILE *file_cont)
{
	instruction_t opcdt[] = {
		{"pall", pall_stc},
		{NULL, NULL}
	};
	unsigned int a;
	char *opcd;

	opcd = strtok(character_content, " \n\t");
	if (opcd && opcd[0] == '#')
		return (0);
	mon.arg_count = strtok(NULL, " \n\t");

	while (opcdt[a].opcode && opcd)
	{
		if (strcmp(opcd, opcdt[a].opcode) == 0)
		{
			opcdt[a].f(stack, character_counter);
			return (0);
		}
		a++;
	}
	if (opcd && opcdt[a].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", character_counter, opcd);
		fclose(file_cont);
		free(character_content);
		free_allstack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
