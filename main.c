#include "monty.h"
#include <stdio.h>
/***/
int main(int ac, char **av)
{
	size_t n = 0;
	ssize_t siize;
	FILE *stream;
	int fd, line_num = 0;
	instruction_t *op;

	if (!(op = malloc(sizeof(instruction_t))))
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	if (ac  != 2)
	{
		write(2, "USAGE: mounty file", 18);
		exit(EXIT_FAILURE);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
	stream = fdopen(fd, "r"); 
	siize = getline(op->opcode, &n, stream);
	printf("%s\n", op->opcode);
	line_num++;
	close(fd);
	free(op);
	return (0);
}
