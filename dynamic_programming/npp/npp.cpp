// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   npp.cpp                                            :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/18 12:10:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/18 13:22:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

int max_elem(int *arr, int n)
{
	int max = 0;
	for (int i = 0; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

int solve(int *arr, int n)
{
    int N[n];
    for (int i = 0; i < n; i++) N[i] = 1;
    
	for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
			if (arr[i] % arr[j] == 0 && N[j] + 1 > N[i]) N[i] = N[j] + 1;

	for (int i = 0; i < n; i++)
		std::cout << N[i] << " ";
	std::cout << std::endl;
	return (max_elem(N, n));
}

int main() {
	int n;
	int arr[10000];
	std::cin >> n;
	for (int i = 0; i < 10000; i++) arr[i] = 0;
	for (int i = 0; i < n; i++)
		std::cin >> arr[i];
	std::cout << solve(arr, n) << std::endl;
	return 0;
}
