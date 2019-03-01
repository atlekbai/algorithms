// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   a.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/04 16:37:15 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/04 16:42:10 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
int x;
int a, b;

void solve(void)
{
	// if (x < 2)
	// {
	// 	std::cout << "-1" << std::endl;
	// 	return ;
	// }
	for (int i = 1; i <= x; i++)
		for (int j = 1; j <= i; j++)
			if (i % j == 0 &&
				i * j > x &&
				i / j < x)
			{
				std::cout << i << " " << j << std::endl;
				return ;
			}
	std::cout << "-1" << std::endl;
}

int main(void)
{
	std::cin >> x;
	solve();
	return (0);
}
