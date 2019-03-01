#include <iostream>

int binary_search(int b, int *a, int low, int high)
{
	if (low > high)
		return (-1);
	int mid = low + (high - low) / 2;
	if (a[mid] == b)
		return (mid);
	if (b < a[mid])
		return (binary_search(b, a, low, mid - 1));
	return (binary_search(b, a, mid + 1, high));
}

int main(void)
{
	int n;
	int k;
	int a[100000];
	int b;
	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cin >> k;
	for (int i = 0; i < k; i++)
	{
		std::cin >> b;
		std::cout << binary_search(b, a, 0, n - 1) << " ";
	}
	std::cout << std::endl;
	return (0);
}
