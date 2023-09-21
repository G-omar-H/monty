#include "monty.h"

/***/
void initialize_args()
{
   
    arg = (argument_t *)malloc(sizeof(argument_t));
    if (arg == NULL)
        malloc_fails();
    arg->op = (instruction_t *)malloc(sizeof(instruction_t));
    if (arg->op == NULL)
        malloc_fails();
    arg->head = NULL;
    arg->line = NULL;
    arg->file = NULL;
    arg->line_number = 0;
    arg->tok_number = 0;
    arg->stack_len = 0;
}
/***/
void free_arr_tokens()
{
    int i = 0;
    
    if (arg->tokens == NULL)
        return;
    while(arg->tokens[i] != NULL)
    {
        free(arg->tokens[i]);
        i++;
    }
    free(arg->tokens);
    arg->tokens = NULL;
}
/***/
void free_args()
{
    if (arg == NULL)
        return;
    if (arg->op != NULL)
    {
        free(arg->op);
        arg->op = NULL;
    }
    free_head();
    if (arg->line != NULL)
    {
        free(arg->line);
        arg->line = NULL;
    }
    free(arg);
    arg = NULL;
}
/***/
void free_head()
{
    if (arg->head != NULL)
        free_stack(arg->head);
    arg->head = NULL;
}

/***/
void free_stack(stack_t *head)
{
    stack_t *node = head;
    if (head == NULL)
        return;
    while (node->next)
    {
        head = node->next;
        free(node);
        node  = head;
    }
    free(node);

}
/***/
void free_all_args()
{
    close_stream();
    free_arr_tokens();
    free_args();
}