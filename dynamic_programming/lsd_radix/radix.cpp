// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   radix.cpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/20 09:45:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/20 11:25:58 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

typedef long long llong;

void show_vec(std::vector<llong> v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

llong byte_len(llong num)
{
	llong count = 0;
	while (num > 0)
	{
		count++;
		num /= 2;
	}
	return (count);
}

void countSort(std::vector<llong> &v, int exp)
{
	std::vector<llong> output(v.size());
	std::vector<llong> count(10, 0);

	for (int i = 0; i < v.size(); i++)
		count[(v[i] / exp) % 2]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = v.size() - 1; i >= 0; i--)
	{
		output[count[(v[i] / exp) % 2] - 1] = v[i];
		count[(v[i] / exp) % 2]--;
	}
	for (int i = 0; i < v.size(); i++)
		v[i] = output[i];
}

void solve(std::vector<llong> &v, llong max)
{
	llong max_bas = byte_len(max);
	int exp = 1;
	for (llong i = 0; i < max_bas; i++)
		countSort(v, exp *= 2);
}

int	main(int ac, char **av)
{
	std::vector<llong> v(ac - 1);
	llong max = 0;
	for (int i = 1; i < ac; i++)
	{
		v[i - 1] = std::atoi(av[i]);
		if (v[i - 1] > max)
			max = v[i - 1];
	}
	solve(v, max);
	show_vec(v);
	return (0);
}
