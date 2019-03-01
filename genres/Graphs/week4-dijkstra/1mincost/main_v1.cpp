#include <iostream>
#include <vector>
#include <queue>
#include <list>
#include <limits>

#define ll long long
#define INF std::numeric_limits<long long>::max()

std::vector<std::vector<std::pair<ll, ll> > >		children;
std::vector<ll> 									dist;
std::vector<ll> 									parent;
std::vector<char> 									mark;

class priority_queue
{
private:
	ll array[100000];
	ll size;
	ll maxSize;

public:
	priority_queue(void)
	{
		init(1);
	}

	priority_queue(ll n)
	{
		init(n);
	}

	void init(ll n)
	{
		size = 0;
		maxSize = n;
	}

	ll extractRoot(void)
	{
		ll res = array[0];
		array[0] = array[size - 1];
		siftDown(0);
		size--;
		return (res);
	}

	bool empty(void) const
	{
		return (size == 0);
	}

	void changePriority(ll i)
	{
		ll index = -1;
		for (ll j = 0; j < size; j++)
			if (array[j] == i)
			{
				index = j;
				break ;
			}
		if (index == -1)
			return ;
		if (dist[array[index]] < dist[array[parent(index)]])
			siftUp(index);
		else
			siftDown(index);
	}

	void insert(ll value)
	{
		if (size == maxSize)
			return;
		array[size] = value;
		siftUp(size);
		size++;
	}

	void siftDown(ll i)
	{
		ll maxIndex = i;
		ll l = leftChild(i);
		ll r = rightChild(i);
		if (l < size && dist[array[maxIndex]] > dist[array[l]])
			maxIndex = l;
		if (r < size && dist[array[maxIndex]] > dist[array[maxIndex]])
			maxIndex = r;
		if (maxIndex != i)
		{
			std::swap(array[i], array[maxIndex]);
			siftDown(maxIndex);
		}
	}

	void siftUp(ll i)
	{
		while (i > 0 && dist[array[i]] < dist[array[parent(i)]])
		{
			std::swap(array[i], array[parent(i)]);
			i = parent(i);
		}
	}

	ll parent(ll n) const
	{
		return ((n - 1) / 2);
	}

	ll leftChild(ll n) const
	{
		return (2 * n + 1);
	}

	ll rightChild(ll n) const
	{
		return (2 * n + 2);
	}

	void	print(void) const
	{
		for (ll i = 0; i < size; i++)
			std::cout << "(" << array[i] << "|" << dist[array[i]] << "), ";
		std::cout << std::endl;
	}
};

void solve(ll u)
{
	ll	current;
	ll	child;
	ll	weight;
	priority_queue queue(100000);

	for (ll i = 0; i < dist.size(); i++)
		queue.insert(i);
	while (!queue.empty())
	{
		// queue.print();
		current = queue.extractRoot();
		// std::cout << current << std::endl;
		for (ll i = 0; i < children[current].size(); i++)
		{
			child	= children[current][i].first;
			weight	= children[current][i].second;
			if (dist[current] + weight < dist[child])
			{
				dist[child] 	= dist[current] + weight;
				parent[child]	= current;
				// std::cout << child << " changed: " << dist[child] << std::endl;
				queue.changePriority(child);
			}
		}
		// queue.print();

	}
}

int main(void)
{
	ll u, v, w;
	ll n, m;
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
	if (dist[v] < 0)
		std::cout << -1;
	else
		std::cout << dist[v];
	return (0);
}