#include <stdio.h>

void ft_swap(int *a, int *b)
{
	int *a_copy = *a;
	int *b_copy = *b;

	*a = b_copy;
	*b = a_copy;
}

