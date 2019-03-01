#include <iostream>

void print_arr(int *a, int s, int n)
{
	for (int i = s; i <= n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

int partition(int *A, int s, int n)
{
	int pivot = A[s];
	int tmp;
	int j = s;
	for (int i = s + 1; i <= n; i++)
	{
		if (A[i] <= pivot)
		{
			j++;
			tmp = A[j];
			A[j] = A[i];
			A[i] = tmp;
		}
	}
	tmp = A[s];
	A[s] = A[j];
	A[j] = tmp;
	return (j);
}

void qsort(int *a, int s, int n)
{
	if (s >= n)
		return ;
	int m = partition(a, s, n);
	qsort(a, s, m - 1);
	qsort(a, m + 1, n);
}

int main(void)
{
	int n;
	int a[1000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	qsort(a, 0, n - 1);
	print_arr(a, 0, n - 1);
	return (0);
}
