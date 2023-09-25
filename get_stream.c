#include "monty.h"
#include <stdio.h>
/**
 * get_stream - Get the stream object
 * @filename: fileanme string
 * Return: void.
 */
void get_stream(char *filename)
{
	int fd;
	size_t n = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		open_fails(filename);
	}
	arg->file = fdopen(fd, "r");
	if (arg->file == NULL)
	{
		close(fd);
		open_fails(filename);
	}
	while (getline(&arg->line, &n, arg->file) != -1)
	{
		arg->line_number += 1;
		tokenize_line();
		if (arg->tok_number > 0)
		{
			if (arg->tokens[0][0] == '#')
			{
				free_arr_tokens();
				continue;
			}
		}
		get_instruct();
		execute_opcode();
		free_arr_tokens();
	}
}
/**
 * close_stream - close file descriptor stream
 * Return: void.
 */
void close_stream(void)
{
	if (!arg->file)
		return;
	fclose(arg->file);
	arg->file = NULL;
}
/**
 * free_all_args - calls all free functions for the project
 *
 * Return: void.
 */
void free_all_args(void)
{
	close_stream();
	free_arr_tokens();
	free_args();
}
