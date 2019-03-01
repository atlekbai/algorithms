#include <iostream>
#include <algorithm>

int64_t solve(int n, long *a, long *b)
{
	int64_t sum = 0;

	std::sort(a, a + n);
	std::sort(b, b + n);
	for (int i = 0; i < n; i++)
		sum += (a[i] * b[i]);
	return (sum);
}

int main(void)
{
	int n;
	long a[1000];
	long b[1000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < n; i++)
		std::cin >> b[i];
	std::cout << solve(n, a, b) << std::endl;
	return (0);
}
