#include <iostream>

void swap(int &a, int &b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

std::pair<int, int> partition(int *a, int low, int high)
{
	int x = a[low];
	int mid = low;
	int count = 0;
	while (mid <= high)
	{
		if (a[mid] < x)
			swap(a[low++], a[mid++]);
		else if (a[mid] == x)
		{
			count++;
			mid++;
		}
		else
			swap(a[mid], a[high--]);
	}
	return (std::make_pair(mid - count, mid - 1));
}

void qsort(int *a, int low, int high)
{
	if (low >= high)
		return ;
	std::pair<int, int> m = partition(a, low, high);
	qsort(a, low, m.first - 1);
	qsort(a, m.second + 1, high);
}

int main(void)
{
	int n;
	int a[100000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	qsort(a, 0, n - 1);
	
	for (int i = 0; i < n; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
	return (0);
}
