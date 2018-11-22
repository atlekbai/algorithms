#include <iostream>
#include <algorithm>

int	solve(int n, int m, int k, int l, int *a)
{
	int q = 0;
	int best_time = 0;
	int best_wait = 2000000000;
	int wait_pers = m;
	int p;
	int i;

	std::sort(a, a + n);
	for (i = 0; i <= k; i++)
	{
		// if (i % l == 0)
		// 	p = l;
		// if (i != 0 && wait_pers > 0 && i % l == 0)
		// 	--wait_pers;
		// if (wait_pers * l + p < best_wait)
		// {
		// 	best_time = i;
		// 	best_wait = wait_pers * l + p;
		// }
		// if (q < n && a[q] == i)
		// {
		// 	++wait_pers;
		// 	++q;
		// }
		// if (p > 0)
		// 	--p;
		// if (i - best_time > 1000000)
		// 	break;
	}
	std::cout << "stop:" << i << std::endl;
	std::cout << "time:" << best_time << std::endl;
	return (best_wait);
}

int main(void)
{
	int t;
	int n;
	int m;
	int l;
	int k;
	int a[100000];

	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> n;
		std::cin >> m;
		std::cin >> k;
		std::cin >> l;
		for (int j = 0; j < n; j++)
			std::cin >> a[j];
		std::cout << solve(n, m, k, l, a) << std::endl;
	}
	return (0);
}