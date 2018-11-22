#include <iostream>
#define MAX 1000

void add(int *A2, int &k, int s1, int s2)
{
	int tmp;
	if (s1 > s2)
	{
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	int d = s2 - s1;
	if (A2[d] != -1)
		A2[d] = std::max(A2[d], s1);
	else
	{
		A2[d] = s1;
		k++;
	}
}

int	solve(int *arr, int n)
{
	int A[MAX + 1];
	int k = 1;

	std::fill(A, A + MAX, -1);
	A[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int A2[MAX + 1];
		int m = 0;
		int s = k;

		std::fill(A2, A2 + MAX, -1);
		for (int j = 0; j < s; j++)
		{
			int sum2 = j + A[j];
			add(A2, m, A[j], sum2);
			add(A2, m, A[j] + arr[i], sum2);
			add(A2, m, A[j], sum2 + arr[i]);
		}
		memcpy(A, A2, MAX + 1);
		k = m;
 	}
	return (A[0]);
}

int	main(int ac, char **av)
{
	int n;
	int arr[MAX];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	int res = solve(arr, n);
	std::cout << res << std::endl;
	return (0);
}
