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
    int n;
    printf("How many numbers: ");
    scanf("%d", &n);

    int v[n];
    printf("Enter values: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }

    sort_int_array(v, n);

    printf("Median: %f\n", n % 2 != 0 ? (float)v[n / 2] : (float)(v[n / 2] + v[n / 2 - 1]) / 2);

    return 0;
}