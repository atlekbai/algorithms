#include <iostream>

int64_t gcd(int a, int b)
{
	if (b == 0)
		return (a);
	a = a % b;
	return (gcd(b, a));
}

int64_t lcm(int a, int b)
{
	int64_t gcd_ = gcd(a, b);
	return (b /gcd_ * a);
}

int main(void)
{
	int a;
	int b;

	std::cin >> a;
	std::cin >> b;
	std::cout << lcm(a, b) << std::endl;
	return (0);
}
