#include <iostream>

int main(void)
{
	unsigned f[100];
	int n;

	std::cin >> n;
	f[0] = 0;
	f[1] = 1;
	for (int i = 2; i <= n; i++)
		f[i] = f[i - 1] + f[i - 2];
	std::cout << f[n] << std::endl;
	return (0);
}
