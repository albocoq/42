#include <stdlib.h>
#include <stdio.h>

void print_subset(int *arr, int *subset, int subset_size)
{
    int i = 0;
    while (i < subset_size)
    {
        printf("%d", subset[i]);
        if (i < subset_size - 1)
            printf(" ");
        i++;
    }
    printf("\n");
}

void find_subsets(int *arr, int arr_size, int target, int *subset, int subset_size, int index, int current_sum)
{
    if (current_sum == target)
    {
        print_subset(arr, subset, subset_size);
        return;
    }

    if (index >= arr_size || current_sum > target)
        return;

    int i = index;
    while (i < arr_size)
    {
        subset[subset_size] = arr[i];
        find_subsets(arr, arr_size, target, subset, subset_size + 1, i + 1, current_sum + arr[i]);
        i++;
    }
}

int main(int ac, char **av)
{
    if (ac < 3)
        return 1;

    int target = atoi(av[1]);
    int arr_size = ac - 2;
    int *arr = malloc(arr_size * sizeof(int));
    int *subset = malloc(arr_size * sizeof(int));

    if (!arr || !subset)
    {
        free(arr);
        free(subset);
        return 1;
    }

    int i = 0;
    while (i < arr_size)
    {
        arr[i] = atoi(av[i + 2]);
        i++;
    }

    find_subsets(arr, arr_size, target, subset, 0, 0, 0);

    free(arr);
    free(subset);
    return 0;
}
