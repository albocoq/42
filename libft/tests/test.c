#include "ft_printf.h"
#include "libft.h"

int main(void)
{
    int fd;
    char *line;

    fd = open("tests/test.txt", O_RDONLY);

    ft_printf("Test de ft_printf : Nombre = %d, Chaîne = %s\n", 42, "libft");
    ft_printf("Test de ft_printf avec %% et caractère : %% %c\n", 'A');

    char *str = ft_strdup("Test ft_strdup");
    if (str)
    {
        ft_printf("Test de ft_strdup : %s\n", str);
        free(str);
    }

    ft_printf("Test de ft_strlen : Longueur = %d\n", ft_strlen("42 Málaga"));


    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    ft_printf("\nGET_NEXT_LINE\n");

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    if (close(fd) == -1)
    {
        perror("Error closing file");
        return 1;
    }

    return 0;

    return (0);
}
