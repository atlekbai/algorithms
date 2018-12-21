// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/20 17:35:39 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/20 17:44:09 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

class tree
{
public:
	int		key;
	int		left;
	int		right;

	tree(int k)
	{
		key = k;
		init();
	}

	void init(void)
	{
		left = -1;
		right = -1;
	}
};

tree *trees[100000];
std::vector<int> v;

void error(void)
{
	std::cout << "INCORRECT" << std::endl;
	exit(0);
}

void check(tree *root)
{
	if (!root)
		return ;
	if (v.size() != 0 && root->key < v.back())
		error();
	if (root->left != -1)
	{
		if (trees[root->left]->key == root->key)
			error();
		check(trees[root->left]);
	}
	v.push_back(root->key);
	if (root->right != -1)
		check(trees[root->right]);
}

int main(void)
{
	int n;
	int key, left, right;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> key >> left >> right;
		trees[i] = new tree(key);
		trees[i]->left = left;
		trees[i]->right = right;
	}
	check(trees[0]);
	std::cout << "CORRECT" << std::endl;
	return (0);
}
