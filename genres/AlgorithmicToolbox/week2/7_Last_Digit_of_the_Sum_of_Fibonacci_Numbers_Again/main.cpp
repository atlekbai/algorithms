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

int64_t fibo(int64_t m, int64_t n)
{
    int a = 0;
    int b = 1;
    int f;
    int sum = 0;

    if (n <= 1) return (n);
    if (m <= 2) sum++;
    for (int i = 2; i < n + 1; i++)
    {
        f = (a + b) % 10;
        a = b;
        b = f;
        if (i >= m)
            sum = (sum + f) % 10;
    }
    return (sum);
}

int main(void)
{
    int64_t a;
    int64_t b;
    int len;

    std::cin >> a;
    std::cin >> b;
    len = period_length(10);
    a = a % len;
    b = b % len;
    std::cout << fibo(a, b) << std::endl;
    return (0);
}
