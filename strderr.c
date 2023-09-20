#include "monty.h"
/**
 * malloc_fails - display to the stderr when malloc fails
 * Return: void.
 */
void malloc_fails()
{
    fprintf(stderr, "Error: malloc failed");
	exit(EXIT_FAILURE);
}
/**
 * invalid_usage - display to the stderr when wrong usage
 * Return: void.
 */
void validate_usage(int ac)
{
    if (ac  == 2)
        return;
    write(2, "USAGE: mounty file", 18);
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
	exit(EXIT_FAILURE);
}
