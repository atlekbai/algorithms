#include <iostream>

void	mult_poly(int n, int *A, int *B)
{
	int	res[2 * n - 1];

	for (int i = 0; i < 2 * n; i++)
		res[i] = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			res[i + j] += A[i] * B[j];
	for (int i = 0; i < 2 * n - 1; i++)
	{
		std::cout << res[i] << "x^" << 2 * n - 2 - i;
		if (i + 1 < 2 * n - 1)
			std::cout << " + ";
	}
}

int		main(void)
{
	int n;
	int A[1000];
	int B[1000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> A[i];
	for (int i = 0; i < n; i++)
		std::cin >> B[i];
	mult_poly(n, A, B);
	return (0);
}
