// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   disjointSet.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/12 11:53:08 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/12 11:54:18 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>

class Set
{
private:
	int *parent;
	int	*rank;
	int size;
public:
	Set(void)
	{
		init(1);
	}
	
	Set(int s)
	{
		init(s);
	}

	void makeSet(int i)
	{
		parent[i] = i;
	}

	void unionSets(int i, int j)
	{
		int iid = find(i);
		int jid = find(j);
		if (iid == jid)
			return ;
		if (parent[iid] > parent[jid])
			parent[iid] = parent[jid];
		else
		{
			parent[jid] = parent[iid];
			// if (rank[iid] == rank[jid])
				// rank[jid]++;
		}
	}

	int	find(int i)
	{
		if (i != parent[i])
			parent[i] = find(parent[i]);
		return (parent[i]);
	}

	void init(int n)
	{
		size = n;
		parent = new int[n];
		rank = new int[n];
		std::fill(parent, parent + n, 0);
		std::fill(rank, rank + n, 0);
	}

	void print(void) const
	{
		for (int i = 0; i < size; i++)
			std::cout << parent[i] << " ";
		std::cout << std::endl;
	}

	void printRank(void) const
	{
		for (int i = 0; i < size; i++)
			std::cout << rank[i] << " ";
		std::cout << std::endl;
	}
};

int main(void)
{
	Set set(13);
	// for (int i = 1; i <= 60; i++)
	// 	set.makeSet(i);
	// for (int i = 1; i <= 30; i++)
	// 	set.unionSets(i, 2 * i);
	// for (int i = 1; i <= 20; i++)
	// 	set.unionSets(i, 3 * i);
	// for (int i = 1; i <= 12; i++)
	// 	set.unionSets(i, 5 * i);
	// for (int i = 1; i <= 60; i++)
	// 	set.find(i);
	// set.printRank();
	for (int i = 1; i <= 12; i++)
		set.makeSet(i);
	set.unionSets(2, 10);
	set.unionSets(7, 5);
	set.unionSets(6, 1);
	set.unionSets(3, 4);
	set.unionSets(5, 11);
	set.unionSets(7, 8);
	set.unionSets(7, 3);
	set.unionSets(12, 2);
	set.unionSets(9, 6);
	set.print();
	std::cout << set.find(6) << std::endl;
	std::cout << set.find(3) << std::endl;
	std::cout << set.find(11) << std::endl;
	std::cout << set.find(9) << std::endl;
	return (0);
}
