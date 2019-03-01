#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int> > v;
std::vector<bool>	visited;
int	cc;

void explore(int u)
{
	visited[u] = true;
	for (int i = 0; i < v[u].size(); i++)
		if (!visited[v[u][i]])
			explore(v[u][i]);
}

int main(void)
{
	int a;
	int b;
	int n;
	int m;

	std::cin >> n >> m;
	
	cc = 0;
	v.resize(n);
	visited.resize(n);
	std::fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < m; i++)
	{
		std::cin >> a >> b;
		v[a - 1].push_back(b - 1);
		v[b - 1].push_back(a - 1);
	}

	for (int i = 0; i < n; i++)
		if (!visited[i])
		{
			explore(i);
			cc++;
		}
	std::cout << cc << std::endl;
	return (0);
}