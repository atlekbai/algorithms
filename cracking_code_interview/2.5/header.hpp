#ifndef HEADER
# define HEADER

#include <iostream>

typedef struct s_list
{
	int n;
	struct s_list *next;
}              t_list;

t_list *create_elem(int d)
{
	t_list *neww = (t_list*)malloc(sizeof(t_list));
	neww->n = d;
	neww->next = NULL;
	return (neww);
}

void add_elem(t_list **head, int d)
{
	if (!*head)
	{
		*head = create_elem(d);
		return;
	}
	t_list *tmp = *head;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = create_elem(d);
}

void print_list(t_list *head)
{
	while (head != NULL)
	{
		std::cout << head->n << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

#endif
