/*
  You have two numbers represented by a linked list, where each node
  contains a single digit The digits are stored in reverse order, such that
  the 1’s digit is at the head of the list Write a function that adds the
  two numbers and returns the sum as a linked list
  EXAMPLE
  Input: (3 -> 1 -> 5) + (5 -> 9 -> 2)
  Output: 8 -> 0 -> 8
*/

#include "header.hpp"

int get_num(t_list *list)
{
	int i = 1;
	int n = 0;
	while (list)
	{
		n += list->n * i;
		i *= 10;
		list = list->next;
	}
	return (n);
}

t_list *solve(t_list *l1, t_list *l2)
{
	t_list *res = NULL;
	int n1 = get_num(l1);
	int n2 = get_num(l2);
	int sum = n1 + n2;
	while (sum > 0)
	{
		add_elem(&res, sum % 10);
		sum /= 10;
	}
	return (res);
}

int main(void)
{
	t_list *list1 = NULL;
	add_elem(&list1, 3);
	add_elem(&list1, 1);
	add_elem(&list1, 5);

	t_list *list2 = NULL;
	add_elem(&list2, 5);
	add_elem(&list2, 9);
	add_elem(&list2, 2);

	print_list(list1);
	std::cout << " + " << std::endl;
	print_list(list2);
	t_list *res = solve(list1, list2);
	print_list(res);
	return (0);
}
