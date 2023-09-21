#include "monty.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */
mon_t mon = {NULL, NULL, NULL, 0};
int main(int argc, char *argv[])
{
	char *character_content;
	FILE *file_cont;
	size_t size = 0;
	ssize_t readContent_line;
	stack_t *stack = NULL;
	unsigned int character_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file_cont = fopen(argv[1], "r");

	if (!file_cont)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (readContent_line > 0)
	{
		character_content = NULL;
		readContent_line = getline(&character_content, &size, file_cont);
		mon.character_content = character_content;
		character_counter++;

		if (readContent_line > 0)
		{
			execute(character_content, &stack, character_counter, file_cont);
		}
		free(character_content);
	}
	free_allstack(stack);
	fclose(file_cont);

	return (0);
}

