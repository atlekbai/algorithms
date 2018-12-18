// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/18 17:26:31 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/18 17:26:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <vector>
#include <cmath>
#define ll long long
#define HASHTABLE std::list<std::string>

class Map
{
private:
	ll			m;
	ll			x;
	ll			p;
	HASHTABLE	*table;
public:
	Map(int n)
	{
		table = init(n);
	}

	HASHTABLE *init(int n)
	{
		HASHTABLE *newTable = new HASHTABLE[n];
		m = n;
		x = 263;
		p = 1000000007;
		return (newTable);
	}

	HASHTABLE *getIndex(ll i)
	{
		i = (i % m + m) % m;
		if (table[i].empty())
			return (NULL);
		return (&table[i]);
	}

	void	del(std::string S)
	{
		if (!hasKey(S))
			return ;
		int index = hashFunction(S);
		table[index].erase(std::remove_if(table[index].begin(), table[index].end(), [S](std::string str){
			return (str == S);
		}), table[index].end());
	}

	void	insert(std::string S)
	{
		if (hasKey(S))
			return ;
		int index = hashFunction(S);
		table[index].push_front(S);
	}

	bool	hasKey(std::string S) const
	{
		int index = hashFunction(S);
		for (auto block: table[index])
			if (block == S)
				return (true);
		return (false);
	}

	int		hashFunction(std::string S) const
	{
		unsigned ll res = 0;
		for (int i = S.size() - 1; i >= 0; --i)
			res = (res * x + S[i]) % p;
		return (res % m + m) % m;
	}

	void print(void)
	{
		for (ll i = 0; i < m; i++)
		{
			std::cout << i << "|";
			if (!table[i].empty())
				for (auto block: table[i])
					std::cout << "--->|" << block << "|";
			std::cout << std::endl;
		}
	}
};

class Manager
{
private:
	Map *map;
public:
	Manager(int n)
	{
		map = new Map(n);
	}

	void add(std::string arg)
	{
		map->insert(arg);
	}

	void del(std::string arg)
	{
		map->del(arg);
	}

	void find(std::string arg)
	{
		if (map->hasKey(arg))
			std::cout << "yes" << std::endl;
		else
			std::cout << "no" << std::endl;
	}

	void check(std::string arg)
	{
		HASHTABLE *res = map->getIndex(std::stoi(arg));
		if (!res)
			NULL;
		else
			for (auto s: *res)
				std::cout << s << " ";
		std::cout << std::endl;
	}

	void process(std::string line)
	{
		std::map<std::string, void (Manager::*)(std::string)> query = {
			{"add", &Manager::add},
			{"del", &Manager::del},
			{"find", &Manager::find},
			{"check", &Manager::check}
		};
		int c = 0;
		std::vector<std::string> v(2);
		for (int i = 0; i < line.length(); i++)
			if (line[i] != ' ')
				v[c] += line[i];
			else
				c++;
		(this->*query[v[0]])(v[1]);
	}

	void print(void) const
	{
		map->print();
	}
};

int main(void)
{
	std::string line;
	int m;
	int N;
	std::cin >> m >> N;
	std::cin.ignore();
	Manager man(m);
	for (int i = 0; i < N; i++)
	{
		std::getline(std::cin, line);
		man.process(line);
	}
	// man.print();
	return (0);
}