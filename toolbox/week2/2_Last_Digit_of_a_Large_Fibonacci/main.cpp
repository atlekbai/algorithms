#include <iostream>

int main(void)
{
	int f;
	int a = 0;
	int b = 1;
	int n;

	std::cin >> n;
	if (n == 1) f = a;
	else if (n == 2) f = b;
	for (int i = 2; i <= n; i++)
	{
		f = (a + b) % 10;
		a = b;
		b = f;
	}
	std::cout << f << std::endl;
	return (0);
}
