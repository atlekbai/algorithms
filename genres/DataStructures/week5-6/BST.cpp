// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   BST.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/20 12:06:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/20 12:12:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>

template<typename T>
class tree
{
private:
	int		size;
public:
	T 		key;
	tree<T> *left;
	tree<T> *right;
	tree<T> *parent;
	tree(void)
	{
		init();
	}

	tree(T keyValue)
	{
		key = keyValue;
		init();
	}

	tree(T keyValue, tree<T> *_parent)
	{
		key = keyValue;
		init();
		parent = _parent;
	}

	void init(void)
	{
		size = 1;
		left = NULL;
		right = NULL;
		parent = NULL;
	}

	void setLeft(tree<T> const *node)
	{
		left = node;
	}

	void setRight(tree<T> const *node)
	{
		right = node;
	}

	void setParent(tree<T> const *node)
	{
		parent = node;
	}

	int getSize(void) const
	{
		return (size);
	}

	/*
	** basic operations
	*/

	tree *find(T const &key, tree<T> *root)
	{
		if (root->key == key)
			return (root);
		else if (key < root->key && root->left)
			return (find(key, root->left));
		else if (root->right)
			return (find(key, root->right));
		return (root);
	}

	tree *next(tree<T> *node)
	{
		if (node->right)
			return (leftDescendant(node->right));
		return (rightAncestor(node));
	}

	tree *leftDescendant(tree<T> *node)
	{
		if (node->left)
			return (leftDescendant(node->left));
		return (node);
	}

	tree *rightAncestor(tree<T> *node)
	{
		if (!node->parent)
			return (NULL);
		else if (node->key > node->parent->key)
			return (rightAncestor(node->parent));
		return (node->parent);
	}

	std::list<T> rangeSearch(T const &lower, T const &upper)
	{
		std::list<T> result;
		tree<T> *node = find(lower, this);
		while (node && node->key <= upper)
		{
			if (node->key >= lower)
				result.push_back(node->key);
			node = next(node);
		}
		return (result);
	}

	void insert(T newKey)
	{
		tree<T> *place = find(newKey, this);
		if (newKey > place->key)
			place->right = new tree<T>(newKey, place);
		else
			place->left = new tree<T>(newKey, place);
		adjustSize();
	}

	void adjustSize(void)
	{
		int ls = 0;
		int rs = 0;
		if (this->left)
			this->left->adjustSize();
		if (this->right)
			this->right->adjustSize();

		if (this->left)
			ls = this->left->size;
		if (this->right)
			rs = this->right->size;
		size = ls + rs + 1;
	}

	tree<T>	*orderStatistics(int k)
	{
		int s = 0;
		if (this->left)
		{
			s = this->left->size;
			if (k == s + 1)
				return (this);
			else if (k < s + 1)
				return (this->left->orderStatistics(k));
			else if (this->right)
				return (this->right->orderStatistics(k - s - 1));
		}
		return (this);
	}

	void del(T keyDelete)
	{

	}

	void print(int i, tree<T> *root) const
	{
		if (!root)
			return ;
		std::cout << "----------" << std::endl;
		std::cout << "level: " << i << std::endl;
		if (root->parent)
			std::cout << "parent: " << root->parent->key << std::endl;
		std::cout << "node: " << root->key << std::endl;
		std::cout << "----------" << std::endl;
		print(i + 1, root->left);
		print(i + 1, root->right);
	}
};

int main(void)
{
	tree<int> *root = new tree<int>(50);
    root->insert(30); 
    root->insert(20); 
    root->insert(40); 
    root->insert(70); 
    root->insert(60); 
    root->insert(80);
    // root->print(0, root);

    std::list<int> range = root->rangeSearch(30, 60);
    for (auto l: range)
    	std::cout << l << std::endl;
    tree<int> *order = root->orderStatistics(8);
    std::cout << "order: " << order->key << std::endl;
	return (0);
}