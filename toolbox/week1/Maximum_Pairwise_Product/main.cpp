#include <iostream>

int64_t solve(int64_t *arr, int n)
{
	int idx[2];

	idx[0] = 0;
	for (int j = 0; j < n; j++)
		if (arr[idx[0]] < arr[j])
			idx[0] = j;

	if (idx[0] == 0)
		idx[1] = 1;
	else
		idx[1] = 0;

	for (int j = 0; j < n; j++)
		if (arr[idx[1]] < arr[j] && j != idx[0])
			idx[1] = j;
	return (arr[idx[0]] * arr[idx[1]]);
}

int main(void)
{
	int n;
	int64_t arr[10000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << solve(arr, n) << std::endl;
	return (0);
}
