#include <iostream>
#include <vector>
#include <algorithm>

std::vector< std::vector<int> > v;
std::vector<bool>	visited;

void explore(int u)
{
	visited[u] = true;
	for (int i = 0; i < v[u].size(); i++)
		if (!visited[v[u][i]])
			explore(v[u][i]);
}

int	main(void)
{
	bool	result;
	int 	a, b;
	int		s, e;
	int		n;
	int		m;

	std::cin >> n >> m;

	v.resize(n);
	visited.resize(n);
	std::fill(visited.begin(), visited.end(), false);

	for (int i = 0; i < m; i++)
	{
		std::cin >> a >> b;
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	std::cin >> s >> e;
	s--;
	e--;
	
	explore(s);
	result = visited[e];
	std::cout << result << std::endl;
	return (0);
}
