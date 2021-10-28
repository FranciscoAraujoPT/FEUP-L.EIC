#include <stdio.h>
#include <limits.h>

void minMax(int a, int *min, int *max)
{
    if (a < *min)
    {
        *min = a;
    }

    if (a > *max)
    {
        *max = a;
    }
}

int main(void)
{
    int n;
    printf("How many numbers? ");
    scanf("%d", &n);

    if (n < 1)
    {
        return 1;
    }

    int min = INT_MAX;
    int max = INT_MIN;
    int sum = 0;
    int v;

    for (int i = 0; i < n; i++)
    {
        printf("Enter value: ");
        scanf("%d", &v);
        minMax(v, &min, &max);
        sum += v;
    }

    printf("min: %d, max=%d, sum=%d\n", min, max, sum);
    return 0;
}