#include <iostream>
#include <iomanip>
#include <algorithm>

struct item
{
	double value;
	double weight;
};

double solve(int n, int W, item *items)
{
	double sum = 0;
	std::sort(items, items + n, [](item a, item b){return (a.value / a.weight > b.value / b.weight);});

	for (int i = 0; i < n; i++)
	{
		if (W <= 0)
			break ;
		double a = 1;
		if (items[i].weight > W)
			a = (double)W / (double)items[i].weight;
		sum += items[i].value * a;
		W -= (double)items[i].weight * a;
	}
	return (sum);
}

int main(void)
{
	int n;
	int W;
	item items[1000];

	std::cin >> n;
	std::cin >> W;
	for (int i = 0; i < n; i++)
	{
		std::cin >> items[i].value;
		std::cin >> items[i].weight;
	}
	std::cout << std::fixed << std::setprecision(4) << solve(n, W, items) << std::endl;
	return (0);
}
