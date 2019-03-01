#include <iostream>
#include <vector>
#include <limits>

#define ll size_t
#define INF std::numeric_limits<long long>::max()

std::vector<std::vector<std::pair<ll, ll> > >		children;
std::vector<ll> 									dist;
std::vector<ll> 									parent;
std::vector<char> 									mark;
ll u, v, w;
ll n, m;

void solve(ll u)
{
	ll	child;
	ll	weight;
	ll 	min;

	for (int i = 0; i < n; i++)
	{
		min = -1;
		for (int j = 0; j < n; j++)
			if (!mark[j] && (min == -1 || dist[j] < dist[min]))
				min = j;
		if (dist[min] == INF)
			break ;
		mark[min] = true;
	
		for (ll i = 0; i < children[min].size(); i++)
		{
			child	= children[min][i].first;
			weight	= children[min][i].second;
			if (dist[min] + weight < dist[child])
			{
				dist[child] 	= dist[min] + weight;
				parent[child]	= min;
			}
		}
	}
}

int main(void)
{
	std::cin >> n >> m;

	children.resize(n);
	parent.resize(n);
	mark.resize(n);
	dist.assign(n, INF);

	for (ll i = 0; i < m; i++)
	{
		std::cin >> u >> v >> w;
		u--;
		v--;
		children[u].push_back(std::make_pair(v, w));
	}
	std::cin >> u >> v;
	u--;
	v--;
	dist[u] = 0;
	solve(u);
	if (dist[v] == INF)
		std::cout << -1;
	else
		std::cout << dist[v];
	return (0);
}