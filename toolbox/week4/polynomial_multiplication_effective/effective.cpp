#include <iostream>

int *mult_poly(int *a, int *b, int n, int a1, int b1)
{
    int *r = new int[2 * n - 1];
    for (int i = 0; i < 2 * n; i++)
        r[i] = 0;
    if (n == 1)
    {
        r[0] = a[a1] * b[b1];
        return (r);
    }
    int mid = n / 2;

    int *d0 = mult_poly(a, b, mid, a1, b1);
    for (int i = 0; i < n - 1; i++)
        r[i] = d0[i];
    int *d1 = mult_poly(a, b, mid, a1 + mid, b1 + mid);
    for (int i = 0; i < n - 1; i++)
        r[n + i] = d1[i];

    int *a2 = new int[mid];
    int *b2 = new int[mid];
    for (int i = 0; i < mid; i++)
    {
        a2[i] = a[i] + a[i + mid];
        b2[i] = b[i] + b[i + mid];
    }
    int *a2b2  = mult_poly(a2, b2, mid, 0, 0);
    for (int i = 0; i < n - 1; i++)
        r[mid + i] += a2b2[i] - d0[i] - d1[i];
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
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	for (int i = 0; i < n; i++)
		std::cin >> b[i];
	solve(n, a, b);
	return (0);
}
