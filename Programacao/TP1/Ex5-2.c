#include <stdio.h>

int mdc(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return mdc(b, a % b);
}

int main(void)
{
    int a, b;
    printf("Enter values: ");
    scanf("%d %d", &a, &b);
    printf("mdc(%d,%d): %d\n", a, b, mdc(a, b));
    return 0;
}