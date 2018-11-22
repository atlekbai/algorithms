#include <iostream>

void arr_cat(int *dest, int &start, int *src, int low, int high)
{
	while (low <= high)
		dest[start++] = src[low++];
}

int merge(int *a, int *tmp, int low, int high)
{
	int num = 0;
	int start = low;
	int mid = low + (high - low) / 2;
	int left_end = mid;
	int right_start = mid + 1;
	int i = 0;

	while (low <= left_end && right_start <= high)
	{
		if (a[low] <= a[right_start])
			tmp[i] = a[low++];
		else
		{
			tmp[i] = a[right_start++];
			num += left_end - low + 1;
		}
		i++;
	}
	arr_cat(tmp, i, a, low, left_end);
	arr_cat(tmp, i, a, right_start, high);
	arr_cat(a, start, tmp, 0, i - 1);
	return (num);
}

int merge_sort(int *a, int *tmp, int low, int high)
{
	if (low >= high)
		return (0);
	int mid = low + (high - low) / 2;
	int num = 0;
	num += merge_sort(a, tmp, low, mid) + merge_sort(a, tmp, mid + 1, high) + merge(a, tmp, low, high);
	return (num);
}

int main(void)
{
	int n;
	int a[100000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	int res = merge_sort(a, new int[n], 0, n - 1);
	std::cout << res << std::endl;
	return (0);
}
