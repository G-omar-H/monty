#include "monty.h"
argument_t *arg = NULL;
/**
 * main - monty interpreter
 * @ac: arguments counter
 * @av: arguments vector
 * Return: int 
 */
int main(int ac, char **av)
{
	size_t n = 0;
	int line_count = 0;

	validate_usage(ac);
	initialize_args();
	get_stream(av[1]);
	while (getline(&arg->line, &n, arg->file) != -1)
	{
		printf("%s", arg->line);
		line_count++;
	}
	fclose(arg->file);
	free(arg);
	return (0);
}
