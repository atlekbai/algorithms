// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   max_coin.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/15 20:27:02 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/15 20:40:51 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

void	show_vec(std::vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << " ";
	std::cout << std::endl;
}

int	max_coin(std::vector<int> v, int n)
{
	std::vector<int> N(n + 1, 0);

	N[0] = 1;
	for(int i = 0; i < v.size(); i++)
		for(int j = v[i]; j <= n; j++)
			N[j] += N[j - v[i]];
	show_vec(N);
	return (N[n]);
}

int	main(int ac, char **av)
{
	std::vector<int> v(ac - 2);
	int n = std::atoi(av[1]);

	for (int i = 2; i < ac; i++)
		v[i - 2] = std::atoi(av[i]);
	int res = max_coin(v, n);
	std::cout << "Max coin exchange: " << res << std::endl;
	return (0);
}
