#include <unistd.h>

int is_valid(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i])
    {
        if (str[i] == '(')
            count++;
        else if (str[i] == ')')
        {
            count--;
            if (count < 0)
                return 0;
        }
        i++;
    }
    return count == 0;
}

void print_solution(char *str, int len)
{
    int i = 0;
    while (i < len)
    {
        if (str[i] == ' ')
            write(1, "_", 1);
        else
            write(1, &str[i], 1);
        i++;
    }
    write(1, " $\n", 3);
}

void remove_parentheses(char *str, int index, int len, int left_rem, int right_rem)
{
    if (left_rem == 0 && right_rem == 0)
    {
        if (is_valid(str))
            print_solution(str, len);
        return;
    }

    int i = index;
    while (i < len)
    {
        if (i > index && str[i] == str[i - 1])
        {
            i++;
            continue;
        }

        if (left_rem > 0 && str[i] == '(')
        {
            char temp = str[i];
            str[i] = ' ';
            remove_parentheses(str, i + 1, len, left_rem - 1, right_rem);
            str[i] = temp;
        }

        if (right_rem > 0 && str[i] == ')')
        {
            char temp = str[i];
            str[i] = ' ';
            remove_parentheses(str, i + 1, len, left_rem, right_rem - 1);
            str[i] = temp;
        }
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

    int left = 0, right = 0;
    int i = 0;
    while (i < len)
    {
        if (str[i] == '(')
            left++;
        else if (str[i] == ')')
        {
            if (left > 0)
                left--;
            else
                right++;
        }
        i++;
    }

    remove_parentheses(str, 0, len, left, right);
    return 0;
}
