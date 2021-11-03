#include <stdio.h>

int length(const char s[])
{
    int res = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {
        res++;
    }

    return res;
}

void copy(char dst[], const char src[])
{
    int aux = 0;

    while (src[aux] != '\0')
    {
        dst[aux] = src[aux];
        aux++;
    }

    dst[aux] = '\0';
}

void concat(char dst[], const char src[])
{
    int aux = 0, size = length(dst);

    while (src[aux] != '\0')
    {
        dst[aux + size] = src[aux];
        aux++;
    }

    dst[aux + size] = '\0';
}

int main(void)
{
    char a[20];

    copy(a, "Hello");
    puts(a);
    printf("%d\n", length(a));

    // Nota: "" é a string vazia (tem apenas '\0' no início)
    concat(a, "");
    puts(a);
    printf("%d\n", length(a));
    concat(a, " world");
    puts(a);
    printf("%d\n", length(a));
    concat(a, "!");
    puts(a);
    printf("%d\n", length(a));

    return 0;
}