#include "cube3d.h"

int only_whitespace(const char *str)
{
    int i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
            return 0;
        i++;
    }
    return 1;
}