#include <stdio.h>

void alineaA(int *a1, int *b1, int *c1, int *d1, int *e1)
{
    int a, b, c, d, e;
    a = 3;             //3
    b = 2;             //2
    c = (a + b) * b;   //10
    d = a + b * b;     //7
    e = c / d + c % d; //4
    *a1 = a;
    *b1 = b;
    *c1 = c;
    *d1 = d;
    *e1 = e;
}

void alineaB(int *a1, int *b1, int *c1, int *d1, int *e1)
{
    int a, b, c, d, e;
    a = 1;   //1
    b = a++; //2
    c = ++a; //3
    d = --a; //2
    e = a--; //1
    *a1 = a;
    *b1 = b;
    *c1 = c;
    *d1 = d;
    *e1 = e;
}

void alineaC(int *a1, int *b1, int *c1, int *d1, int *e1)
{
    int a = 10, b = -20, c = 0x1E, d = -40, e = 50;
    b += a; // -10
    c -= a; // 20
    d *= a; // -400
    e /= a; // 5
    *a1 = a;
    *b1 = b;
    *c1 = c;
    *d1 = d;
    *e1 = e;
}

void alineaD(int *a1, int *b1, int *c1, int *d1, int *e1)
{
    int a, b, c, d, e;
    a = 1;               // 1
    b = a % 2 == 1;      // 1
    c = a > 0 && b < 0;  // 0
    d = c == 1 || b > 0; // 1
    e = !d ? 0 : 1;      // 1
    *a1 = a;
    *b1 = b;
    *c1 = c;
    *d1 = d;
    *e1 = e;
}

int main(void)
{
    int a, b, c, d, e;

    alineaA(&a, &b, &c, &d, &e);
    printf("a) a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
    alineaB(&a, &b, &c, &d, &e);
    printf("b) a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
    alineaC(&a, &b, &c, &d, &e);
    printf("c) a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);
    alineaD(&a, &b, &c, &d, &e);
    printf("d) a=%d b=%d c=%d d=%d e=%d\n", a, b, c, d, e);

    return 0;
}