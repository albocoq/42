#include "libft.h"

char **ft_realloc(char **ptr, size_t new_size)
{
    char **new_ptr;
    size_t i;

    new_ptr = (char **)malloc(new_size);
    if (!new_ptr)
        return NULL;
    i = 0;
    while (ptr && ptr[i] && i < (new_size / sizeof(char *)))
    {
        new_ptr[i] = ptr[i];
        i++;
    }
    while (i < (new_size / sizeof(char *)))
    {
        new_ptr[i] = NULL;
        i++;
    }
    free(ptr);
    return new_ptr;
}