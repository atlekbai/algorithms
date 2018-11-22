#include <iostream>

int g = 0;

void print(int a, int b)
{
	for (int i = 0; i < b - a; i++)
		std::cout << ">";
	std::cout << "  ";
}

int *mult_poly(int *a, int *b, int n, int a1, int b1)
{
	int *r = new int[2 * n - 1];
	for (int i = 0; i < 2 * n; i++)
		r[i] = 0;
	print(n, g);
	std::cout << "size: " << n << std::endl;
	if (n == 1)
	{
		print(n, g);
		std::cout << "\033[00;32m" << a[a1] << " * " <<  b[b1] << " = " << a[a1] * b[b1] << " <----\033[0m\n";
		r[0] = a[a1] * b[b1];
		return (r);
	}
	int mid = n / 2;
	print(n, g);
	std::cout << "mid: " << mid << std::endl;


	int *d0 = mult_poly(a, b, mid, a1, b1);
	print(n, g);
	std::cout << "R1[" << 0 << "..." << n - 2 << "] = ";
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << d0[i] << " ";
		r[i] += d0[i];
	}
	std::cout << " ::: " << n << "| " << a1 << "..." << b1 << std::endl;


	int *d1 = mult_poly(a, b, n - mid, a1 + mid, b1 + mid);
	print(n, g);
	std::cout << "R2[" << n << "..." << 2 * n - 2 << "] = ";
	for (int i = 0; i < n; i++)
	{
		std::cout << d1[i] << " ";
		r[i + mid * 2] += d1[i];
	}
	std::cout << " ::: " << n << "| " << a1 << "..." << b1 << std::endl;


	int *d0e1 = mult_poly(a, b, n - mid, a1, b1 + mid);
	int *d1e0 = mult_poly(a, b, n - mid, a1 + mid, b1);
	print(n, g);
	std::cout << "R3[" << mid << "..." << mid + n - 2 << "] = ";
	for (int i = 0; i < n - 1; i++)
	{
		std::cout << d0e1[i] << " + " << d1e0[i] << " | ";
		r[mid + i] += d0e1[i] + d1e0[i];
	}
	std::cout << " ::: " << n << "| " << a1 << "..." << b1 << std::endl;
	return (r);
}

void solve(int n, int *a, int *b)
{
	int *res = mult_poly(a, b, n, 0, 0);
	for (int i = 0; i < 2 * n - 1; i++)
		std::cout << res[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	int n;
	int a[1000];
	int b[1000];

	std::cin >> n;
	g = n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < n; i++)
		std::cin >> b[i];
	solve(n, a, b);
	return (0);
}
