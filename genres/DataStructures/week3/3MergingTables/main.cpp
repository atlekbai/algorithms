// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/13 14:15:33 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/13 14:15:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>

int max = 0;

class Set
{
private:
	int parent[100001];
	int rank[100001];
	int size;
public:
	Set(void)
	{
		init(1);
	}

	Set(int n)
	{
		init(n);
	}

	void makeSet(int i)
	{
		parent[i] = i;
	}

	void unionSets(int i, int j)
	{
		i -= 1;
		j -= 1;
		int iParent = find(i);
		int jParent = find(j);
		if (iParent == jParent)
			return ;
		parent[jParent] = parent[iParent];
		rank[iParent] += rank[jParent];
		if (rank[iParent] > max)
			max = rank[iParent];
		rank[j] = -1;
	}

	int find(int i)
	{
		if (i != parent[i])
			parent[i] = find(parent[i]);
		return (parent[i]);
	}

	void init(int n)
	{
		size = n;
		std::fill(parent, parent + n, 0);
		std::fill(rank, rank + n, 0);
	}

	void setRank(int i, int r)
	{
		rank[i] = r;
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
	int r;
	int d, s;
	int n, m;
	std::cin >> n >> m;
	Set set(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> r;
		if (r > max)
			max = r;
		set.makeSet(i);
		set.setRank(i, r);
	}
	// std::cout << "links" << std::endl;
	// set.print();
	// std::cout << "ranks" << std::endl;
	// set.printRank();
	// std::cout << "----->" << std::endl;
	for (int i = 0; i < m; i++)
	{
		std::cin >> d >> s;
		set.unionSets(d, s);
		std::cout << max << std::endl;
	}
	// std::cout << "links" << std::endl;
	// set.print();
	// std::cout << "ranks" << std::endl;
	// set.printRank();
	return (0);
}