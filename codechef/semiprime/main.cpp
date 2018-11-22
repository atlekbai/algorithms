// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/12 17:49:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/10/12 17:52:36 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#define NMAX 200

int		*list_of_prime(void)
{
	int i = 2;
	int *arr = new int(NMAX);
	int k = 0;
	int j;

	while (k < NMAX)
	{
		j = 1;
		while (++j < i)
		{
			if (i % j == 0)
				break;
		}
		if (j == i)
			arr[k++] = i;
		i++;
	}
	return (arr);
}

bool	solve(int N, int t)
{
	int canbe[NMAX + 1] = {};
	int *arr = list_of_prime();
	int semi[NMAX + 1] = {};
	for (int k = 0; k < NMAX + 1; k++)
		for (int i = 0; i < NMAX; i++)
			for (int j = i; j < NMAX;j++)
				if (i != j && semi[k] == 0 && arr[i] * arr[j] == k)
					semi[k] = 1;

	for (int k = 0; k < NMAX + 1; k++)
		for (int i = 0; i < NMAX + 1; i++)
			if (semi[i] == 1)
				for (int j = 0; j < NMAX + 1; j++)
					if (semi[j] == 1 && canbe[k] == 0 && i + j == k)
						canbe[k] = 1;
	if (canbe[N] == 1)
		return (true);
	return (false);
}

int		main(void)
{
	int	t;
	int N[NMAX] = {};
	std::cin >> t;
	for (int i = 0; i < t; i++)
		std::cin >> N[i];
	for (int i = 0; i < t; i++)
		std::cout << (solve(N[i], t) ? "YES" : "NO") << std::endl;
	return (0);
}
