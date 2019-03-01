// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   subsequence.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/14 20:56:40 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/14 21:47:34 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>

template<typename T>
void 	show(std::vector<T> v, std::string s)
{
	std::cout << s << std::endl;
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] << "\t";
	std::cout << std::endl << std::endl;
}

int 	get_max(std::vector<int> v)
{
	int max = 0;
	int max_i = 0;
	for (int i = 0; i < v.size(); i++)
		if (v[i] > max)
		{
			max = v[i];
			max_i = i;
		}
	return (max_i);
}

void	show_sequence(std::vector<int> v, std::vector<int> n, int i)
{
	if (n[i] == 0)
	{
		std::cout << v[i] << " ";
		return ;
	}
	else
		show_sequence(v, n, n[i] - 1);
	std::cout << v[i] << " ";
}

int		subsequence(std::vector<int> v)
{
	std::vector<int> n(v.size());
	std::vector<int> l(v.size());

	n[0] = 0;
	l[0] = 1;
	for (int i = 1; i < v.size(); i++)
	{
		for (int j = 0; j < i; j++)
			if (v[j] < v[i]) n[i] = j + 1;
		l[i] = l[n[i] - 1] + 1;
	}
	show(n, "N");
	show(v, "V");
	show(l, "L");
	show_sequence(v, n, get_max(l));
	std::cout << std::endl;
	return (get_max(l));
}

int 	main(int ac, char **av)
{
	std::vector<int> v(ac - 1);
	for (int i = 1; i < ac; i++)
		v[i - 1] = std::atoi(av[i]);
	int res = subsequence(v);
	std::cout << "Length of biggest growing seq = " << res << std::endl;
	return (0);
}
