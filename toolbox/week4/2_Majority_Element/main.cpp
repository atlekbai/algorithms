#include <iostream>

int count_range(int num, int *a, int low, int high)
{
	int count = 0;
	for (int i = low; i <= high; i++)
		if (a[i] == num)
			count++;
	return (count);
}

int solve(int *a, int low, int high)
{
	if (low >= high)
		return (a[low]);
	int mid = low + (high - low) / 2;
	int left = solve(a, low, mid);
	int right = solve(a, mid + 1, high);
	if (left == right)
		return (left);
	int left_count = count_range(left, a, low, high);
	int right_count = count_range(right, a, low, high);
	if (left_count < right_count && right_count > high / 2)
		return (right);
	else if (left_count > right_count && left_count > high / 2)
		return (left);
	else
		return (-1);
}

int main(void)
{
	int n;
	int a[100000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	std::cout << (solve(a, 0, n - 1) != -1) << std::endl;
	return (0);
}
