#include <stdio.h>

void invert(int n, const int a[], int b[])
{
    for (int i = 0; i < n; i++)
    {
        b[i] = a[n - i - 1];
    }
}

void print(int n, const int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", i, a[i]);
    }
}

int main(void)
{
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    int b[7];
    invert(7, a, b);
    print(7, a);
    print(7, b);
    return 0;
}