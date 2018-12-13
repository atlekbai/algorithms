// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/08 22:09:36 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/08 23:00:14 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>

int bracketType(char c)
{
	if (c == '(') return (1);
	else if (c == ')') return (-1);
	else if (c == '[') return (2);
	else if (c == ']') return (-2);
	else if (c == '{') return (3);
	else if (c == '}') return (-3);
	return (0);
}

int solve(std::string S)
{
	int i = 0;
	int counter = 0;
	std::list<char> stack;
	std::list<int>	index;
	while (S[i])
	{
		while (S[i] && bracketType(S[i]) == 0) i++;
		if (!S[i]) continue;
		if (stack.empty() && bracketType(S[i]) < 0)
			return (i + 1);
		else if (stack.empty() || 
			(bracketType(stack.front()) > 0 && bracketType(S[i]) > 0))
		{
			counter++;
			stack.push_front(S[i]);
			index.push_front(i);
		}
		else if (bracketType(stack.front()) == -bracketType(S[i]))
		{
			stack.pop_front();
			index.pop_front();
		}
		else if (bracketType(stack.front()) != -bracketType(S[i]))
			return (i + 1);

		i++;
	}
	if (stack.size() != 0)
		return (index.back() + 1);
	return (0);
}

int main(void)
{
	std::string S;

	std::getline(std::cin, S);
	int res = solve(S);
	if (res == 0)
		std::cout << "Success";
	else
		std::cout << res;
	std::cout << std::endl;
	return (0);
}
