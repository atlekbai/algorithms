/*
  Write code to remove duplicates from an unsorted linked list
  FOLLOW UP
  How would you solve this problem if a temporary buffer is not allowed?
*/

#include <iostream>

typedef struct	s_list
{
	int n;
	struct s_list *next;
}				t_list;

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

void solve(t_list **head)
{
	t_list *tmp = *head;
	t_list *j;
	t_list *tail = *head;

	tmp = tmp->next;
	while (tmp)
	{
		j = *head;
		while (j != tmp)
		{
			if (j->n == tmp->n)
				break;
			j = j->next;
		}
		
		if (j == tmp)
		{
			tail->next = tmp;
			tail = tail->next;
		}
		tmp = tmp->next;
	}
	tail->next = NULL;
}

int main(void)
{
	t_list *list = NULL;

	add_elem(&list, 1);
	add_elem(&list, 2);
	add_elem(&list, 2);
	add_elem(&list, 4);
	add_elem(&list, 2);
	add_elem(&list, 2);

	print_list(list);
	solve(&list);
	print_list(list);
	return (0);
}
