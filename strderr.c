#include "monty.h"

/**
 * invalid_usage - display to the stderr when wrong usage
 * Return: void.
 */
void validate_usage(int ac)
{
	if (ac  == 2)
		return;
	fprintf(stderr, "USAGE: mounty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_fails - display to the stderr when malloc fails
 * Return: void.
 */
void malloc_fails()
{
	fprintf(stderr, "Error: malloc failed\n");
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * open_fails - display to the stderr when open fails
 * @filename: mounty file name string
 * Return: void.
 */
void open_fails(char *filename)
{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	free_args();
	exit(EXIT_FAILURE);
}

/***/
void invalid_instruction()
{
	fprintf(stderr, "L%d: unknown instruction %s\n", arg->line_number, arg->tokens[0]);
	close_stream();
	free_args();
	free_arr_tokens();
	exit(EXIT_FAILURE);
}

/***/
void wrong_push(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_args();
	free_arr_tokens();

	exit(EXIT_FAILURE);
}
