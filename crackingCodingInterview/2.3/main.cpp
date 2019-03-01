/*
  Implement an algorithm to delete a node in the middle of a single linked list, given only access to that node
  EXAMPLE
  Input: the node ‘c’ from the linked list a->b->c->d->e
  Result: nothing is returned, but the new linked list looks like a->b->d->e
*/

#include "header.hpp"

t_list *find(t_list *head, int d)
{
	while (head)
	{
		if (head->n == d)
			return (head);
		head = head->next;
	}
	return (NULL);
}

void	delete_node(t_list **head, t_list *list)
{
	t_list *tmp = *head;

	if (tmp == list)
	{
		*head = tmp->next;
		return;
	} 
	while (tmp)
	{
		if (tmp->next == list)
			tmp->next = tmp->next->next;
		tmp = tmp->next;
	}
}

int main(void)
{
	t_list *list = NULL;
	
	add_elem(&list, 1);
	add_elem(&list, 2);
	add_elem(&list, 3);
	add_elem(&list, 4);
	add_elem(&list, 5);
	add_elem(&list, 6);
	
	print_list(list);
	
	t_list *hah = find(list, 1);

	delete_node(&list, hah);
	free(hah);

	print_list(list);
	return (0);
}
