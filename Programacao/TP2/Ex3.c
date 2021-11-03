#include <stdio.h>
#include <string.h>

int hexstr_convert(const char h[])
{
    int r = 0, length = strlen(h), base = 1;
    for (int i = length; i >= 0; i--)
    {
        if (h[i] >= '0' && h[i] <= '9')
        {
            r += (h[i] - 48) * base;
            base *= 16;
        }
        else if (h[i] >= 'A' && h[i] <= 'F')
        {
            r += (h[i] - 55) * base;
            base *= 16;
        }
        else if (h[i] >= 'a' && h[i] <= 'f')
        {
            r += (h[i] - 87) * base;
            base *= 16;
        }
    }
    return r;
}

void test(const char h[])
{
    int v = hexstr_convert(h);
    printf("\"%s\" -> %d (%X)\n", h, v, v);
}

int main(void)
{
    test("A");
    test("0a");
    test("a0");
    test("18");
    test("1f");
    test("fF");
    test("ffff");
    test("AbCdEf");
    test("7fffffff");
    return 0;
}