#include <stdio.h>

void invert(int n, int a[])
{
    int aux;

    for (int i = 0; i < n / 2 + 1; i++)
    {
        aux = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = aux;
    }
}

void print(int n, int a[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d: %d\n", i, a[i]);
    }
}

int main(void)
{
    int a[7] = {0, 1, 2, 3, 4, 5, 6};
    print(7, a);
    invert(7, a);
    print(7, a);
    return 0;
}