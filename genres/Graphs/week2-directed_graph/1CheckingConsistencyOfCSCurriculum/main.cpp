#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > children;
std::vector<int> visited;

void explore(int n)
{
	visited[n]++;
	for (int i = 0; i < children[n].size(); i++)
		if (visited[children[n][i]] <= 1)
			explore(children[n][i]);
}

int main(void)
{
	int u, v;
	int n, m;

	std::cin >> n >> m;

	visited.resize(n);
	children.resize(n);
	std::fill(visited.begin(), visited.end(), 0);

	for (int i = 0; i < m; i++)
	{
		std::cin >> u >> v;
		children[u - 1].push_back(v - 1);
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
			explore(i);
		if (visited[i] > 1)
		{
			std::cout << 1 << std::endl;
			return (0);
		}
		else
			std::fill(visited.begin(), visited.end(), 0);
	}
	std::cout << 0 << std::endl;
	return (0);
}
