#include <iostream>
#include <vector>
#include <list>
#define ll long long
#define MAX_VALUE -1

std::vector<std::vector<ll> >	children;

std::vector<ll>				dist;
std::vector<ll>				prev;

void bfs(ll start)
{
	ll				current;
	ll				child;
	std::list<ll>	queue;

	dist[start] = 0;
	queue.push_front(start);
	while (!queue.empty())
	{
		current = queue.front();
		queue.pop_front();
		for (ll i = 0; i < children[current].size(); i++)
		{
			child = children[current][i];

			if (dist[child] != -1)
				continue ;
			queue.push_front(child);
			dist[child] = dist[current] + 1;
			prev[child] = current;
		}
	}
}

int main(void)
{
	ll n, m;
	ll u, v;
	ll f, t;
	std::cin >> n >> m;
	
	children.resize(n);
	dist.assign(n, -1);
	prev.assign(n, -1);

	for (ll i = 0; i < m; i++)
	{
		std::cin >> f >> t;
		f--;
		t--;
		children[f].push_back(t);
		children[t].push_back(f);
	}
	std::cin >> u >> v;
	u--;
	v--;
	bfs(u);
	std::cout << dist[v] << std::endl;
	return (0);
}
