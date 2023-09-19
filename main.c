#include "monty.h"

/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: Always 0
 */

int main(int argc, char *argv[]) {
    FILE *file_cont;
  
    unsigned int character_counter = 0;

    if (argc != 2) {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file_cont = fopen(argv[1], "r");

    if (!file_cont) {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (1) {
        char buffer[1024];

        if (fgets(buffer, sizeof(buffer), file_cont) == NULL) {
            break;
        }

    
        character_counter++;
    }

    fclose(file_cont);

    printf("Number of lines: %u\n", character_counter);

    return (0);
}

