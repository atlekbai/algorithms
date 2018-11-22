#include <iostream>
#include <algorithm>

void turn_biggest(int *a, int size)
{
	a[size - 1] = 1;
}

bool solve(int n, int k, int *a)
{
	int sum = 0;
	int sum_sqrt = 0;
	int size = n;
	std::sort(a, a + n);
	for (int i = 0; i < k; i++)
		turn_biggest(a, size--);
	for (int i = 0; i < n; i++)
	{
		sum += a[i];
		sum_sqrt += a[i] * a[i];
	}
	return (sum_sqrt <= sum);
}

int main(void)
{
	int t;
	int k;
	int n;
	int a[10000];

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		std::cin >> k;
		for (int j = 0; j < n; j++)
			std::cin >> a[j];
		std::cout << (solve(n, k, a) ? "YES" : "NO") << std::endl;
	}
	return (0);
}