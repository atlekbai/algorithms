#include <iostream>

int solve(int a, int b)
{
	if (b == 0)
		return (a);
	a = a % b;
	return (solve(b, a));
}

int main(void)
{
	int a;
	int b;

	std::cin >> a;
	std::cin >> b;
	std::cout << solve(a, b) << std::endl;
	return (0);
}
