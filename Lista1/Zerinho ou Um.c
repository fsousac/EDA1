#include <stdio.h>

int main()
{
    short int a, b, c;
    scanf("%hd %hd %hd", &a, &b, &c);

    if (a == b && a == c)
    {
        printf("empate\n");
    }
    else if (a != b && a != c)
    {
        printf("A\n");
    }
    else if (b != a && b != c)
    {
        printf("B\n");
    }
    else if (c != a && c != b)
    {
        printf("C\n");
    }
}