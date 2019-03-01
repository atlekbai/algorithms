#include <iostream>
#include <vector>
#include <list>

#define WHITE 1
#define BLACK 2

std::vector<std::vector<int> > children;
std::vector<int>				color;
// std::vector<int>				prev;

bool bfs(int s)
{
	int				period = 0;
	int				current;
	int				child;
	std::list<int>	queue;

	color[s] = WHITE;
	queue.push_front(s);
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop_front();
		for (int i = 0; i < children[current].size(); i++)
		{
			child = children[current][i];
			if (color[child] == color[current])
				return (false);
			if (color[child] != 0)
				continue ;
			color[child] = (color[current] == WHITE) ? BLACK : WHITE;
			queue.push_front(child);
		}
		period++;
	}
	return (true);
}

int main(void)
{
	int u, v;
	int n, m;

	std::cin >> n >> m;
	children.resize(n);
	color.assign(n, 0);
	// prev.assign(n, 0);

	for (int i = 0; i < m; i++)
	{
		std::cin >> u >> v;
		u--;
		v--;
		children[u].push_back(v);
		children[v].push_back(u);
	}
	std::cout << bfs(0) << std::endl;
	return (0);
}