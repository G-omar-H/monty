#include "monty.h"
/***/
void initialize_args()
{
    arg = (argument_t *)malloc(sizeof(argument_t));
    if (!arg)
        malloc_fails();
    arg->line = NULL;
    arg->file = NULL;

}
/***/
void get_stream(char *filename)
{
    int fd; 

    fd = open(filename, O_RDONLY);
    if (fd == -1)
        open_fails(filename);
    arg->file = fdopen(fd, "r");
    if (arg->file == NULL)
    {
        close(fd);
        open_fails(filename);
    }
}

