// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/10 16:13:28 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/10 16:13:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>

class Stack
{
public:
	std::list<int>	stack;
	std::list<int>	maxes;
	Stack(void){}
	void push(int n)
	{
		if (stack.empty())
			maxes.push_front(n);
		else if (n >= maxes.front())
			maxes.push_front(n);
		stack.push_front(n);
	}

	void pop(void)
	{
		if (stack.front() == maxes.front())
			maxes.pop_front();
		stack.pop_front();
	}

	void max(void)
	{
		std::cout << maxes.front() << std::endl;
	}

	void process(std::string s)
	{
		if (s == "max")
			return (max());
		else if (s == "pop")
			return (pop());
		return (push(std::atoi(s.substr(5).c_str())));
	}
};

int main(void)
{
	std::string line;
	Stack	s;
	int		n;
	std::cin >> n;
	std::cin.ignore();
	for (int i = 0; i < n; i++)
	{
		std::getline(std::cin, line);
		s.process(line);
	}
	return (0);
}