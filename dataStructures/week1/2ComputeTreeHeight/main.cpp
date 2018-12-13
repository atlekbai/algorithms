// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/09 12:36:13 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/09 13:21:27 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

std::vector<std::vector<int>>	tree;
std::vector<int>				parent;
std::vector<int>				dist;

int main(void)
{
	int p;
	int n;
	int root;
	int maxDist = 0;
	std::cin >> n;
	tree.resize(n);
	dist.resize(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> p;
		parent.push_back(p);
		if (p == -1)
		{
			root = i;
			dist[i] = 1;
		}
		else
			tree[p].push_back(i);
	}

	std::vector<int> stack;
	stack.push_back(root);
	while (!stack.empty())
	{
		int current = stack.back();
		stack.pop_back();
		for (int i = 0; i < tree[current].size(); i++)
			stack.push_back(tree[current][i]);
		if (parent[current] != -1)
		{
			dist[current] = 1 + dist[parent[current]];
			if (dist[current] > maxDist)
				maxDist = dist[current];
		}
	}
	std::cout << maxDist << std::endl;
	return (0);
}
