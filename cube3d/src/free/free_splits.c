#include "cube3d.h"

void free_splits(char **splits)
{
    int i;

    if (!splits)
        return;

    i = 0;
    while (splits[i])
    {
        free(splits[i]);
        i++;
    }
    free(splits);
}
