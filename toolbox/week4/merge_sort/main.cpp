#include <iostream>

void print_arr(int *arr, int s, int e)
{
	for (int i = s; i < e; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void arrcat(int *arr, int &j, int *src, int a, int r)
{
	while (a <= r)
		arr[j++] = src[a++];
}

void merge(int *arr, int *temp, int l, int r)
{
	int left_end = (l + r) / 2;
	int a = l;
	int b = left_end + 1;
	int j = 0;

	for (j = 0; a <= left_end && b <= r; j++)
		if (arr[a] <= arr[b])
			temp[j] = arr[a++];
		else
			temp[j] = arr[b++];
	arrcat(temp, j, arr, a, left_end);
	arrcat(temp, j, arr, b, r);
	arrcat(arr, l, temp, 0, j - 1);
}

void merge_sort(int *arr, int *temp, int l, int r)
{
	if (l >= r)
		return ;
	int mid = (l + r) / 2;
	merge_sort(arr, temp, l, mid);
	merge_sort(arr, temp, mid + 1, r);
	merge(arr, temp, l, r);
}

int main(void)
{
	int n;
	int arr[1000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];

	merge_sort(arr, new int[n], 0, n - 1);

	print_arr(arr, 0, n);
	return (0);
}
