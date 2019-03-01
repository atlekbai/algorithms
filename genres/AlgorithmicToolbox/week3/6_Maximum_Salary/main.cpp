#include <iostream>

bool is_great(int a, int b)
{
	std::string res1;
	std::string res2;

	res1 = std::to_string(a) + std::to_string(b);
	res2 = std::to_string(b) + std::to_string(a);
	return (stoi(res1) < stoi(res2));
}

void solve(int n, int *a)
{
	int len = n;
	std::string answer;
	while (len > 0)
	{
		int max = 0;
		while (a[max] == -1 && max < n)
			max++;
		for (int i = 0; i < n; i++)
			if (a[i] != -1 && is_great(a[max], a[i]))
				max = i;
		answer += std::to_string(a[max]);
		a[max] = -1;
		len--;
	}
	std::cout << answer << std::endl;
}

int main(void)
{
	int n;
	int a[1000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	solve(n, a);
	return (0);
}
