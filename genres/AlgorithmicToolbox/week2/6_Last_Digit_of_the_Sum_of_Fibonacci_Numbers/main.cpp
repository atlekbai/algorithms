#include <iostream>

int period_length(int base)
{
    int a = 0;
    int b = 1;
    int f;
    int i = 0;

    while (1)
    {
        f = (a + b) % base;
        a = b;
        b = f;
        i++;
        if (a == 0 && b == 1)
            break;
    }
    return (i);
}

int64_t fibo(int64_t n)
{
    int a = 0;
    int b = 1;
    int f;
    int sum = 1;

    if (n <= 1) return (n);
    for (int i = 2; i < n + 1; i++)
    {
        f = (a + b) % 10;
        a = b;
        b = f;
        sum = (sum + f) % 10;
    }
    return (sum);
}

int main(void)
{
    int64_t n;
    int len;

    std::cin >> n;
    len = period_length(10);
    n = n % len;
    std::cout << fibo(n) << std::endl;
    return (0);
}
