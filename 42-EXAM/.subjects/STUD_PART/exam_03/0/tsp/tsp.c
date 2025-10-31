#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
    float x, y;
} Point;

float distance(Point a, Point b)
{
    return sqrtf((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

float calculate_path_length(Point *cities, int *path, int n)
{
    float total = 0;
    int i = 0;
    while (i < n)
    {
        total += distance(cities[path[i]], cities[path[(i + 1) % n]]);
        i++;
    }
    return total;
}

void generate_permutations(Point *cities, int *path, int start, int n, float *min_distance)
{
    if (start == n - 1)
    {
        float current_distance = calculate_path_length(cities, path, n);
        if (current_distance < *min_distance)
            *min_distance = current_distance;
        return;
    }

    int i = start;
    while (i < n)
    {
        swap(&path[start], &path[i]);
        generate_permutations(cities, path, start + 1, n, min_distance);
        swap(&path[start], &path[i]);
        i++;
    }
}

int main()
{
    Point cities[11];
    int n = 0;
    char line[100];

    while (fgets(line, sizeof(line), stdin))
    {
        if (sscanf(line, "%f, %f", &cities[n].x, &cities[n].y) == 2)
            n++;
    }

    if (n <= 1)
    {
        printf("0.00\n");
        return 0;
    }

    int *path = malloc(n * sizeof(int));
    int i = 0;
    while (i < n)
    {
        path[i] = i;
        i++;
    }

    float min_distance = INFINITY;
    generate_permutations(cities, path, 1, n, &min_distance);

    printf("%.2f\n", min_distance);
    free(path);
    return 0;
}
