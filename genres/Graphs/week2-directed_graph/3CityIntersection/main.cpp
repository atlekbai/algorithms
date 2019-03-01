#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

std::vector<std::vector<int> >	children;
std::vector<std::vector<int> >	reverse;
std::vector<bool>				visited;
std::list<int>				order;

void dfs1(int n)
{
	visited[n] = true;
	for (int i = 0; i < children[n].size(); i++)
		if (!visited[children[n][i]])
			dfs1(children[n][i]);
	order.push_front(n);
}

void dfs2(int n)
{
	visited[n] = true;
	for (int i = 0; i < reverse[n].size(); i++)
		if (!visited[reverse[n][i]])
			dfs2(reverse[n][i]);
}

int main(void)
{
	int cc = 0;
	int u, v;
	int n, m;

	std::cin >> n >> m;

	visited.assign(n, false);
	children.resize(n);
	reverse.resize(n);

	for (int i = 0; i < m; i++)
	{
		std::cin >> u >> v;
		children[u - 1].push_back(v - 1);
		reverse[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
			dfs1(i);

	std::fill(visited.begin(), visited.end(), false);
	while(!order.empty())
	{
		int to = order.front();
		order.pop_front();
		if (!visited[to])
		{
			dfs2(to);
			cc++;
		}
	}
	std::cout << cc << std::endl;
	return (0);
}