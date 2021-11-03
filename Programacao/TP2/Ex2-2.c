#include <stdio.h>

int length(const char s[])
{
    const char *p = &s[0]; // ou simplesmente p = s
    while (*p != '\0')
    {
        p++; // avança para próxima posição
    }
    return p - &s[0]; // ou p - s
}

void copy(char dst[], const char src[])
{
    const char *s = &src[0];
    char *d = &dst[0];

    while (*s != '\0')
    {
        *d = *s;
        s++;
        d++;
    }

    *d = '\0';
}

void concat(char dst[], const char src[])
{
    const char *s = &src[0];
    char *d = &dst[0] + length(dst);

    while (*s != '\0')
    {
        *d = *s;
        s++;
        d++;
    }

    *d = '\0';
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