// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   sequence_01.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/14 15:01:29 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/14 15:05:43 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int	sequence(int n)
{
	int arr[n];

	arr[0] = 2;
	arr[1] = 3;
	for (int i = 2; i < n; i++)
		arr[i] = arr[i - 1] + arr[i - 2];
	return (arr[n - 1]);
}

int main(int ac, char **av)
{
	int res = sequence(std::atoi(av[1]));
	std::cout << "Result: [" << av[1] << "] = " << res << std::endl;
	return (0);
}
