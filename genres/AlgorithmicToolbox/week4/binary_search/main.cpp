#include <iostream>
#include <algorithm>

int binary_search(int k, int *arr, int low, int high)
{
	if (high < low)
		return (-1);
	int mid = low + (high - low) / 2;
	if (arr[mid] == k)
		return (mid);
	if (k > arr[mid])
		return (binary_search(k, arr, mid + 1, high));
	return (binary_search(k, arr, low, mid - 1));
}

int main(void)
{
	int k;
	int arr[1000];

	std::cin >> k;
	for (int i = 0; i < 10; i++)
		std::cin >> arr[i];
	std::sort(arr, arr + 10);
	int res = binary_search(k, arr, 0, 10);
	std::cout << "index: " << res << std::endl;
	return (0);
}
