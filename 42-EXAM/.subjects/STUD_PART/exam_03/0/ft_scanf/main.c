#include <stdio.h>
#include <string.h>

int ft_scanf(const char *format, ...);

int main(void)
{
    char c;
    int d;
    char s[100];
    int result;

    printf("Testing ft_scanf:\n");

    // Test char
    printf("Enter a character: ");
    result = ft_scanf("%c", &c);
    printf("ft_scanf returned: %d, char: '%c'\n", result, c);

    // Test int
    printf("Enter an integer: ");
    result = ft_scanf("%d", &d);
    printf("ft_scanf returned: %d, int: %d\n", result, d);

    // Test string
    printf("Enter a string: ");
    result = ft_scanf("%s", s);
    printf("ft_scanf returned: %d, string: '%s'\n", result, s);

    return 0;
}
