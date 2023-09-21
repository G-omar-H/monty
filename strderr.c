#include "monty.h"

/**
 * validate_usage - ckeck the programme usage
 * display to the stderr when wrong usage
 * @ac: argument counter.
 * Return: void.
 */
void validate_usage(int ac)
{
	if (ac  == 2)
		return;
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * malloc_fails - display to the stderr when malloc fails
 * Return: void.
 */
void malloc_fails(void)
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

/**
 * invalid_instruction - stderr & exit failure
 *
 * Return: void.
 */
void invalid_instruction(void)
{
	fprintf(stderr, "L%d: unknown instruction %s\n",
		arg->line_number, arg->tokens[0]);
	close_stream();
	free_arr_tokens();
	free_args();
	exit(EXIT_FAILURE);
}

/**
 * wrong_push - stderr & exit failure
 * @line_number: line number tracker
 * Return: void
 */
void wrong_push(unsigned int line_number)
{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	free_all_args();
	exit(EXIT_FAILURE);
}
