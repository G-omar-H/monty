#include "monty.h"

/**
 * tokenize_line - do parcing line by delimiter string
 *
 * Return: void.
*/
void tokenize_line(void)
{
	int i = 0;
	char *token = NULL, *line_copy = NULL, *delims = " \n\t";

	arg->tok_number = 0;
	line_copy = malloc(sizeof(char) * (strlen(arg->line) + 1));
	strcpy(line_copy, arg->line);
	token = strtok(line_copy, delims);
	while (token != NULL)
	{
		arg->tok_number += 1;
		token = strtok(NULL, delims);
	}
	arg->tokens = malloc(sizeof(char *) * (arg->tok_number + 1));
	if (arg->tokens == NULL)
		malloc_fails();
	strcpy(line_copy, arg->line);
	token = strtok(line_copy, delims);
	while (token != NULL)
	{
		arg->tokens[i] = malloc(sizeof(char) * (strlen(token) + 1));
		if (arg->tokens[i] == NULL)
			malloc_fails();
		strcpy(arg->tokens[i], token);
		token = strtok(NULL, delims);
		i++;
	}
	arg->tokens[i] = NULL;
	free(line_copy);
}
