#include <stdio.h>
#include <math.h>

int solve_eq(int a, int b, int c, double *x1, double *x2)
{
    if (a == 0)
    {
        return -1;
    }

    int delta = b * b - 4 * a * c;
    int sols = 0;
    if (delta > 0)
    {
        *x1 = (double)(-b + sqrt(delta)) / (2 * a);
        *x2 = (double)(-b - sqrt(delta)) / (2 * a);
        sols = 2;
    }
    else if (delta == 0)
    {
        *x1 = *x2 = (double)-b / (2 * a);
        sols = 1;
    }

    return sols;
}

int main(void)
{
    int a, b, c, sols;
    double x1, x2;

    printf("Enter values for a, b, and c: ");
    scanf("%d %d %d", &a, &b, &c);

    sols = solve_eq(a, b, c, &x1, &x2);

    if (sols == 0)
    {
        printf("No solutions!\n");
    }
    else if (sols == 1)
    {
        printf("One solution: %f\n", x1);
    }
    else if (sols == 2)
    {
        printf("Two solutions: %f and %f\n", x1, x2);
    }
    else
    {
        printf("Error: a is 0!\n");
    }
    return 0;
}