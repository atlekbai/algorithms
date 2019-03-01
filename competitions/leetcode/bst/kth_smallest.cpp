/*
* @Author: atlekbai
* @Date:   2019-03-01 15:45:20
* @Last Modified by:   atlekbai
* @Last Modified time: 2019-03-01 19:34:35
* @Desciption: Order Statistics BST
*/
#include <iostream>
#include <initializer_list>

struct node {
	int		value;
	int		count;
	node	*left;
	node	*right;
	
	node(int v) : value(v), left(NULL), right(NULL), count(1){}
	node(std::initializer_list<int> l) {
		auto it = l.begin();
		value = *it++;
		count = 1;
		left = NULL;
		right = NULL;
		while (it != l.end())
			insert(*it++);
	}

	node* kth(int k) {
		if (!left && !right)
			return (this);
		if (!left)
		{
			if (k >= count)
				return (right->kth(k - 1));
			return (this);
		}
		int s = left->count;
		if (k == s + 1)
			return (this);
		if (k < s + 1)
			return (left->kth(k));
		return (right->kth(k - (s + 1)));
	}

	node* find(int v) {
		count++;
		if (left && v < value)
			return (left->find(v));
		if (right && v > value)
			return (right->find(v));
		return (this);
	}

	void insert(int v) {
		node *tmp = find(v);
		if (v < tmp->value)
			tmp->left = new node(v);
		else
			tmp->right = new node(v);
	}

	node* delete_node(int v) {
		if (v < left->value)
			left = left->delete_node(v);
		else if (v > right->value)
			right = right->delete_node(v);
		else {
			if (!left && !right)
			{
				delete this;
				return (NULL);
			}
			if (!left || !right)
			{
				node *tmp = (left ? left : right);
				delete this;
				return (tmp);
			}
			if (left && right) {
				node *tmp = right;
				while (tmp->left)
					tmp = tmp->left;
				this->value = tmp->value;
				right = right->delete_node(this->value);
			}
		}
		return this;
	}
};

std::ostream& operator<<(std::ostream &out, node const *tmp) {
	out << std::endl;
	out << "node value: " << tmp->value << std::endl;
	out << "node count: " << tmp->count << std::endl;
	if (tmp->left)
		out << "node left: " << tmp->left->value << std::endl;
	if (tmp->right)
		out << "node right: " << tmp->right->value << std::endl;

	if (tmp->left) out << tmp->left;
	if (tmp->right) out << tmp->right;
	return out;
}

int main(void)
{
	node *start = new node({5, 2, 6, 1, 7, 4 ,3});
	for (int i = 0; i < 11; i++)
		std::cout << i << "th element: " << start->kth(i)->value << std::endl;
	return (0);
}