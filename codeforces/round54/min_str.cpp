// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   min_str.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 16:38:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/12 17:07:31 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

std::string solve(std::string str)
{
	std::string res;
	bool rem = false;
	char big = 0;
	for (int i = 1; i < str.length(); i++)
	{
		if (str[i - 1] > str[i] && rem == false)
		{
			rem = true;
			continue ;
		}
		res += str[i - 1];
	}
	if (rem == true)
		res += str[str.length() - 1];
	return (res);
}

int main(void)
{
	int n;
	char c;
	std::string str;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> c;
		str += c;
	}
	std::string res;
	res = solve(str);
	std::cout << res << std::endl;
	return (0);
}
