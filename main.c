#include "monty.h"
#include <stdio.h>
/***/
int main(int ac, char **av)
{
	char **arr = NULL;
	int fd, line_num = 0, i = 0;
	size_t n = 0;
	FILE *stream;
	instruction_t *op;

	(void)arr;
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
	while (getline(&op->opcode, &n, stream) != -1)
	{
		printf("%s\n",op->opcode);
		line_num++;
		i++;
	}
	fclose(stream);
	free(op);
	return (0);
}
