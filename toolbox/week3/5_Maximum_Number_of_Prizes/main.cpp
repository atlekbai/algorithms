#include <iostream>
#include <vector>

void solve(int n)
{
	int i = 0;
	std::vector<int> v;

	while (n > 0)
	{
		i++;
		if (n - i <= i)
		{
			v.push_back(n);
			break;
		}
		n -= i;
		v.push_back(i);
	}
	std::cout << i << std::endl;
	for (int j = 0; j < i; j++)
		std::cout << v[j] << " ";
}

int main(void)
{
	int n;

	std::cin >> n;
	solve(n);
	return (0);
}
