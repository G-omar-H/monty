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
	validate_usage(ac);
	initialize_args();
	get_stream(av[1]);
	close_stream();
	free_args();
	return (0);
}
