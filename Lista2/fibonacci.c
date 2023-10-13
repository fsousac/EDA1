#include <stdio.h>

long int fib[100] = {0};

long int fibonacci(int n)
{
    if (n <= 2)
    {
        fib[n] = 1;
        return 1;
    }

    else if (fib[n] == 0)
    {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    }

    return fib[n];
}

int main()
{
    int n;
    scanf("%d", &n);
    long int resposta = fibonacci(n);
    printf("%ld\n", resposta);
    return 0;
}