#include <iostream>
#include <vector>
#include <algorithm>

struct seg
{
	int a;
	int b;
};

void solve(int n, seg *segs)
{
	int num = 0;
	std::vector<int> v;
	std::sort(segs, segs + n, [](seg a, seg b)
			  {
				  return (a.a < b.a);
			  });

	std::sort(segs, segs + n, [](seg a, seg b)
			  {
				  return (a.b < b.b);
			  });

	for (int i = 0; i < n; i++)
	{
		int j = 0;
		int a = 0;
		for (j = i; j < n; j++)
			if (segs[j].a <= segs[i].b)
			{
				if (segs[j].a > a)
					a = segs[j].a;
			}
			else
				break;
		v.push_back(a);
		num++;
		i = j - 1;
	}
	std::cout << num << std::endl;
	for (int i = 0; i < num; i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int main(void)
{
	int n;
	seg segs[100];

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> segs[i].a;
		std::cin >> segs[i].b;
	}
	solve(n, segs);
	return (0);
}
