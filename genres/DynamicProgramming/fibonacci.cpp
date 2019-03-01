// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   fibonacci.cpp                                      :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/14 10:10:44 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/14 10:22:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int64_t fibonacci(int n)
{
	int64_t arr[n];

	arr[0] = 1;
	arr[1] = 1;
	for (int i = 2; i <= n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	return (arr[n]);
}

int64_t fibonacci_1_res(int n, int64_t **arr)
{
	if (n < 2)
		return (1);
	if ((*arr)[n] != 0)
		return ((*arr)[n]);
	(*arr)[n] = fibonacci_1_res(n - 1, arr) + fibonacci_1_res(n - 2, arr);
	return ((*arr)[n]);
}

int64_t fibonacci_1(int n)
{
	int64_t *arr = new int64_t[n + 1];
	for (int i = 0; i <= n; i++)
		arr[i] = 0;
	return (fibonacci_1_res(n, &arr));
}

int	main(int ac, char **av)
{
	//int64_t res = fibonacci(std::atoi(av[1]));
	int64_t res = fibonacci_1(std::atoi(av[1]));
	std::cout << "Result: [" << av[1] << "] " << res << std::endl;
	return (0);
}
