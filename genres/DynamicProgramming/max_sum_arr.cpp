// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   max_sum_arr.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/15 14:23:17 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/15 15:28:53 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void show_arr(int *n, int l)
{
	for (int i = 0; i < l; i++)
		std::cout << n[i] << " ";
	std::cout << std::endl;
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int max_sum(int *n, int l)
{
	int *incl = new int[l];
	int *excl = new int[l];

	for (int i = 0; i < l; i++)
	{
		incl[i] = 0;
		excl[i] = 0;
	}
	incl[0] = n[0];
	for (int i = 1; i < l; i++)
	{
		incl[i] = max(excl[i - 1] + n[i], incl[i - 1]);
		excl[i] = incl[i - 1];
	}
	//std::cout << "Inclusive: " << std::endl;
	show_arr(incl, l);
	//std::cout << "Exclusive: " << std::endl;
	show_arr(excl, l);
	return (incl[l - 1]);
}

int main(int ac, char **av)
{
	freopen(av[1], "r", stdin);
	
	int l;
	std::cin >> l;
	int *n = new int[l];
	for(int i = 0; i < l; i++)
		std::cin >> n[i];
	int res = max_sum(n, l);
	std::cout << "Max sum array: " << res << std::endl;
	return (0);
}
