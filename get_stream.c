#include "monty.h"
/***/
void get_stream(char *filename)
{
	int fd;
	size_t n = 0;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		free_args();
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
