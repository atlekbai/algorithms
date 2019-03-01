#include <iostream>

int solve(int m)
{
	int i = 0;
	int avail[] = {10, 5, 1};

	while (m > 0)
	{
		for (int j = 0; j < 3; j++)
			if (m - avail[j] >= 0)
			{
				m -= avail[j];
				break ;
			}
		i++;
	}
	return (i);
}

int main(void)
{
	int m;

	std::cin >> m;
	std::cout << solve(m) << std::endl;
	return (0);
}
