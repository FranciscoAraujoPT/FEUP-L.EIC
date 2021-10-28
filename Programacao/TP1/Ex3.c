#include <stdio.h>

void minMaxSum(int a, int b, int *min, int *max, int *sum)
{
    if (a <= b)
    {
        *min = a;
        *max = b;
    }
    else
    {
        *min = b;
        *max = a;
    }

    *sum = a + b;
}

int main(void)
{
    // Read values
    int a, b;
    printf("Enter values: ");
    scanf("%d %d", &a, &b);

    // Calculate min, max, and sum
    int min, max, sum;
    minMaxSum(a, b, &min, &max, &sum);
    printf("min: %d, max: %d, sum: %d\n", min, max, sum);
    return 0;
}