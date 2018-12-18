// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/17 14:33:39 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/18 11:08:04 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

#define ll long long
#define HASHTABLE std::list<std::pair<ll, std::string> >

class PhoneBook
{
private:
	ll			a;	/* factor 1 */
	ll			b;	/* factor 2 */
	ll			p;	/* big prime bumber */
	ll			m;	/* cardinaltiy */
	ll			size;
	HASHTABLE	*table;

public:
	PhoneBook(void)
	{
		size = 0;
		table = init(4);
	}

	~PhoneBook(void)
	{
		delete[] table;
	}

	HASHTABLE *init(ll n)
	{
		HASHTABLE *newTable = new HASHTABLE[n];
		m = n;
		p = m + 3;
		a = rand() % (p - 1) + 1;
		b = rand() % (p - 1) + 1;
		return (newTable);
	}

	void rehash(void)
	{
		double loadFactor = getLoadFactor();
		if (loadFactor >= 1)
		{
			ll oldM = m;
			HASHTABLE *newTable = init(2 * m);
			for (ll i = 0; i < oldM; i++)
				for (auto block: table[i])
					insert(newTable, block.first, block.second);
			delete[] table;
			table = newTable;
		}
	}

	bool hasKey(ll key)
	{
		ll index = hashFunction(key);
		for (auto block: table[index])
			if (block.first == key)
				return (true);
		return (false);
	}

	std::string *get(ll key)
	{
		ll index = hashFunction(key);
		for (auto block = table[index].begin(); block != table[index].end(); block++)
			if (block->first == key)
				return (&block->second);
		return (NULL);
	}

	void	del(ll key)
	{
		ll index = hashFunction(key);
		if (table[index].empty())
			return ;
		table[index].erase(std::remove_if(table[index].begin(), table[index].end(), [key](std::pair<int, std::string> p){
			return (p.first == key);
		}), table[index].end());
	}

	void	set(ll key, std::string value)
	{
		ll index = hashFunction(key);
		for (auto block = table[index].begin(); block != table[index].end(); block++)
			if (block->first == key)
			{
				block->second = value;
				return ;
			}
		table[index].push_back(std::make_pair(key, value));
		size++;
		rehash();
	}

	void	insert(HASHTABLE *t, ll key, std::string value)
	{
		ll index = hashFunction(key);
		t[index].push_back(std::make_pair(key, value));
	}

	ll hashFunction(ll key)
	{
		return ((a * key + b) % p) % m;
	}

	/*
	** Ideally load factor should be 0.5 < ⍺ < 1
	*/
	double getLoadFactor(void) const
	{
		return (static_cast<double>(size) / static_cast<double>(m));
	}

	void print(void)
	{
		std::cout << "cardinality " << getLoadFactor() << std::endl;
		for (ll i = 0; i < m; i++)
		{
			std::cout << i << "|";
			if (!table[i].empty())
				for (auto block: table[i])
					std::cout << "--->|" << block.first << " : " << block.second << "|";
			std::cout << std::endl;
		}
	}
};

class Interpreter
{
private:
	PhoneBook *p;

public:
	Interpreter(void)
	{
		p = new PhoneBook();
	}
	
	~Interpreter(void)
	{
		delete p;
	}

	void add(std::string number, std::string name)
	{
		p->set(std::stoi(number), name);
	}

	void del(std::string number)
	{
		p->del(std::stoi(number));
	}

	void find(std::string number)
	{
		std::string *s = p->get(std::stoi(number));
		if (s)
			std::cout << *s << std::endl;
		else
			std::cout << "not found" << std::endl;
	}

	void process(std::string const &line)
	{
		std::vector<std::string> v(3);
		int i = 0;
		for (int j = 0; j < line.length(); j++)
			if (line[j] != ' ')
				v[i] += line[j];
			else
				i++;
		if (v[0] == "add")
			add(v[1], v[2]);
		else if (v[0] == "find")
			find(v[1]);
		else if (v[0] == "del")
			del(v[1]);
	}

	void print(void) const
	{
		p->print();
	}

};

int main(void)
{
	Interpreter ller;
	std::string line;
	ll n;
	std::cin >> n;
	std::cin.ignore();
	for (ll i = 0; i < n; i++)
	{
		std::getline(std::cin, line);
		ller.process(line);
	}
	std::cout << std::endl;
	ller.print();
	return (0);
}
