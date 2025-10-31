#include <stdlib.h>
#include <unistd.h>

void print_solution(int *board, int n)
{
    int i = 0;
    while (i < n)
    {
        char c = board[i] + '0';
        write(1, &c, 1);
        if (i < n - 1)
            write(1, " ", 1);
        i++;
    }
    write(1, "\n", 1);
}

int is_safe(int *board, int row, int col)
{
    int i = 0;
    while (i < col)
    {
        if (board[i] == row ||
            board[i] - i == row - col ||
            board[i] + i == row + col)
            return 0;
        i++;
    }
    return 1;
}

void solve_nqueens(int *board, int col, int n)
{
    if (col == n)
    {
        print_solution(board, n);
        return;
    }

    int row = 0;
    while (row < n)
    {
        if (is_safe(board, row, col))
        {
            board[col] = row;
            solve_nqueens(board, col + 1, n);
        }
        row++;
    }
}

int main(int ac, char **av)
{
    if (ac != 2)
        return 1;

    int n = atoi(av[1]);
    if (n <= 0)
        return 1;

    int *board = malloc(n * sizeof(int));
    if (!board)
        return 1;

    solve_nqueens(board, 0, n);
    free(board);
    return 0;
}
