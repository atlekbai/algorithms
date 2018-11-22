#include <iostream>

int solve(int *arr, int n, int L)
{
	int i = 0;
	int num = 0;

	while (i + 1 < n)
	{
		int last = i;
		while (i <= n && arr[i + 1] - arr[last] <= L)
			i++;
		if (last == i)
			return (-1);
		if (i <= n)
			num++;
	}
	return (num - 1);
}

int main(void)
{
	int n;
	int arr[1000];
	int L;

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cin >> L;
	std::cout << solve(arr, n, L) << std::endl;
	return (0);
}
