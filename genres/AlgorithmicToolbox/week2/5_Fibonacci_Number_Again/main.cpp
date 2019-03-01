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

int64_t fibo(int64_t n, int base)
{
	int a = 0;
    int b = 1;
    int f;

	if (n <= 1) return (n);
	else if (n == 2) return (b);
    for (int i = 2; i < n + 1; i++)
    {
        f = (a + b) % base;
        a = b;
        b = f;
    }
	return (f);
}

int main(void)
{
	int64_t n;
	int base;
	int len;

	std::cin >> n;
	std::cin >> base;
	len = period_length(base);
	n = n % len;
	std::cout << fibo(n, base) << std::endl;
	return (0);
}
