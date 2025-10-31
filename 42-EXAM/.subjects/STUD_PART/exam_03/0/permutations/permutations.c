#include <unistd.h>

void swap(char *a, char *b)
{
    char temp = *a;
    *a = *b;
    *b = temp;
}

void print_permutation(char *str, int len)
{
    write(1, str, len);
    write(1, "\n", 1);
}

void generate_permutations(char *str, int start, int len)
{
    if (start == len - 1)
    {
        print_permutation(str, len);
        return;
    }

    int i = start;
    while (i < len)
    {
        swap(&str[start], &str[i]);
        generate_permutations(str, start + 1, len);
        swap(&str[start], &str[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    char *str = av[1];
    int len = 0;
    while (str[len])
        len++;

    generate_permutations(str, 0, len);
    return 0;
}
