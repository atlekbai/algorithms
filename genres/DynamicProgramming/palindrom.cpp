// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   palindrom.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/15 11:41:57 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/15 13:04:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

void show_arr(int **n, int a)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
			std::cout << n[i][j] << "\t";
		std::cout << std::endl;
	}
}

int max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int **two_arr(int len)
{
	int **L = new int*[len];

    L[0] = new int [len * len];
    for (int i = 0; i < len * len; i++)
		L[0][i] = 0;
    for (int i = 1; i < len; i++)
		L[i] = L[i - 1] + len;
	return (L);
}

int	palindrom(std::string s)
{
	int len = s.length();
	int **L = two_arr(len);
	int **N = two_arr(len);

	for (int i = 0; i < len; i++)
	{
		L[i][i] = 1;
		N[i][i] = i;
	}
	for (int i = 0; i < len; i++)
		for (int j = i - 1; j >= 0; j--)
			if (s[i] == s[j])
			{
				L[i][j] = L[i - 1][j + 1] + 2;
				N[i][j] = N[i - 1][j + 1];
			}
			else
			{
				L[i][j] = max(L[i - 1][j], L[i][j + 1]);
				if (L[i][j] == L[i - 1][j]) N[i][j] = N[i - 1][j];
				else N[i][j] = N[i][j + 1];
			}
	show_arr(L, len);
	//std::cout << std::endl;
	//show_arr(N, len);
	return (L[len - 1][0]);
}

int	main(int ac, char **av)
{
	int res = palindrom(std::string(av[1]));
	std::cout << "Length of biggest palindrom = " << res << std::endl;
	return (0);
}
