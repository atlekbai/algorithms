// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   a.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/23 15:38:54 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/23 15:55:21 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>

void solve(std::list<char> s)
{
	std::list<char> res;
	int len = s.size();
	int i = 0;
	while (++i <= len)
		if ((len % 2 == 0 && i % 2 != 0) || (len % 2 == 1 && i % 2 == 0))
		{
			res.push_front(s.back());
			s.pop_back();
		}
		else
		{
			res.push_front(s.front());
			s.pop_front();
		}
	for (auto c: res)
		std::cout << c;
	std::cout << std::endl;
}

int main(void)
{
	std::string s;
	std::list<char> str;
	std::getline(std::cin, s);
	for (int i = 0; i < s.length(); i++)
		str.push_back(s[i]);
	solve(str);
	return (0);
}
