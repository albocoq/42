#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
    if (ac != 2 || !av[1][0])
        return 1;

    char *s = av[1];
    int len = strlen(s);
    char *buf = malloc(1024);
    if (!buf)
    {
        perror("Error: ");
        return 1;
    }

    int n;
    while ((n = read(0, buf, 1024)) > 0)
    {
        for (int i = 0; i < n; i++)
        {
            int match = 1;
            for (int j = 0; j < len && i + j < n; j++)
            {
                if (buf[i + j] != s[j])
                {
                    match = 0;
                    break;
                }
            }
            if (match && i + len <= n)
            {
                for (int k = 0; k < len; k++)
                    write(1, "*", 1);
                i += len - 1;
            }
            else
                write(1, &buf[i], 1);
        }
    }
    if (n == -1)
    {
        perror("Error: ");
        free(buf);
        return 1;
    }
    free(buf);
    return 0;
}
