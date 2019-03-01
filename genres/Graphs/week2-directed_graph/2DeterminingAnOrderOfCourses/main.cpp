#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::vector<std::vector<int> >	children;
// std::vector<std::vector<int> >	parents;

std::vector<bool>				visited;
std::vector<bool>				active;

std::list<int>					order;

void explore(int n)
{
	visited[n] = true;
	for (int i = 0; i < children[n].size(); i++)
		if (!visited[children[n][i]] || active[children[n][i]])
			explore(children[n][i]);
	order.push_front(n);
	active[n] = false;
}

int main(void)
{
	int u, v;
	int n, m;

	std::cin >> n >> m;

	visited.resize(n);
	active.resize(n);
	children.resize(n);
	std::fill(visited.begin(), visited.end(), false);
	std::fill(active.begin(), active.end(), true);

	for (int i = 0; i < m; i++)
	{
		std::cin >> u >> v;
		children[u - 1].push_back(v - 1);
		// parents[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
			explore(i);
	for (auto e: order)
		std::cout << e + 1 << " ";
	std::cout << std::endl;
	return (0);
}
