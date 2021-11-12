#include <stdlib.h>
#include <stdio.h>

int compare_int(const void *v1, const void *v2)
{
    return (*(int *)v1) - (*(int *)v2);
}

void sort_int_array(int a[], int n)
{
    qsort(a, n, sizeof(int), &compare_int);
}

int main(void)
{

    int *v = (int *)malloc(sizeof(int)), count = 0, v_size = 1;
    printf("Enter values: ");

    while (scanf("%d", &v[count]) != EOF && v[count] != 0)
    {
        count++;
        if (v_size == count)
        {
            v_size *= 2;
            v = realloc(v, v_size * sizeof(int));
        }
    }

    if (count > 0)
    {
        sort_int_array(v, count);
        printf("Median: %f\n", count % 2 != 0 ? (float)v[count / 2] : (float)(v[count / 2] + v[count / 2 - 1]) / 2);
    }

    free(v);
    return 0;
}