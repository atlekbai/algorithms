/*
  Imagine a (literal) stack of plates If the stack gets too high, it might topple There-
  fore, in real life, we would likely start a new stack when the previous stack exceeds
  some threshold Implement a data structure SetOfStacks that mimics this SetOf-
  Stacks should be composed of several stacks, and should create a new stack once
  the previous one exceeds capacity SetOfStacks push() and SetOfStacks pop() should
  behave identically to a single stack (that is, pop() should return the same values as it
  would if there were just a single stack)
  -- FOLLOW UP --
  Implement a function popAt(int index) which performs a pop operation on a speci c sub-stack
*/

#include <iostream>
#include <cstdio>

// Node of Stack
template<typename T>
struct node
{
	T		data;
	node	*next;
};

template<typename T>
node<T> *create_node(T data)
{
	node<T> *new_node = new node<T>();
	new_node->data = data;
	new_node->next = NULL;
	return (new_node);
}

// Stack
template<typename T>
struct stack
{
	node<T>		*top;
	int			size;
	stack<T>	*next;

	stack(void) : size(0), top(NULL), next(NULL) {}

	T pop(void)
	{
		if (top != NULL)
		{
			node<T> *tmp = top;
			T item = top->data;
			top = top->next;
			delete tmp;
			tmp = NULL;
			size--;
			return (item);
		}
		return (static_cast<T>(NULL));
	}

	void push(node<T> *new_node)
	{
		new_node->next = top;
		top = new_node;
		size++;
	}
};

// Set of Stacks
template<typename T>
class SetOfStacks
{
// private:
public:
	stack<T> 	*head;
	int			threshold;
// public:
	SetOfStacks(void) : threshold(10), head(NULL) {}
	SetOfStacks(int n) : threshold(n), head(NULL) {}
	~SetOfStacks(void){}

	T		pop(void)
	{
		if (head != NULL && head->size > 0)
		{
			stack<T> *tmp = head;
			while (tmp->next) 
				tmp = tmp->next;
			if (tmp && tmp->size == 0)
			{
				pop_stack();
				return (pop());
			}
			else
			{
				T data = tmp->pop();
				return (data);
			}
		}
		throw "Error";
	}

	void	push(T data)
	{
		if (head == NULL)
			head = new stack<T>();
		node<T> *new_node = create_node(data);
		stack<T> *tmp = head;
		while (tmp && tmp->size + 1 > threshold)
			tmp = tmp->next;
		if (tmp == NULL)
			tmp = add_stack();
		tmp->push(new_node);
	}

	stack<T>	*add_stack(void)
	{
		stack<T> *tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new stack<T>();
		return (tmp->next);
	}

	void		pop_stack(void)
	{
		stack<T> *tmp = head;
		if (tmp == NULL)
			return;
		if (tmp->next == NULL)
		{
			delete tmp;
			tmp = NULL;
		}

		while (tmp->next->next)
			tmp = tmp->next;
		delete tmp->next;
		tmp->next = NULL;
	}
};



int main(void)
{
	int j = 0;
	SetOfStacks<int> set;

	for (int i = 0; i < 35; i++)
		set.push(i);
	stack<int> *s = set.head;
	for (int i = 0; i < 36; i++)
	{
		try
		{
			int popped = set.pop();
		}
		catch (std::exception &e)
		{
			std::cout << "Error " << std::endl;
		}
	}
	while (s)
	{
		std::cout << "Stack #" << j++ << std::endl;
		while (s->top)
		{
			std::cout << s->top->data << std::endl;
			s->top = s->top->next;
		}
		s = s->next;
	}
	return (0);
}
