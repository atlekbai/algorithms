// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 23:49:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/12 23:49:49 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>

int ft_min(int a, int b, int c)
{
	int arr[3] = {a, b, c};
	std::sort(arr, arr + 3);
	return (arr[0]);
}

int solve(std::string s1, std::string s2)
{
	int arr[101][101];
	int len1 = s1.length();
	int len2 = s2.length();

	for (int i = 0; i <= len1; i++)
		arr[i][0] = i;
	for (int i = 0; i <= len2; i++)
		arr[0][i] = i;
	for (int i = 1; i <= len1; i++)
		for (int j = 1; j <= len2; j++)
		{
			if (s1[i - 1] == s2[j - 1])
				arr[i][j] = ft_min(arr[i - 1][j - 1],
								   arr[i - 1][j] + 1,
								   arr[i][j - 1] + 1);
			else
				arr[i][j] = ft_min(arr[i - 1][j - 1] + 1,
								   arr[i - 1][j] + 1,
								   arr[i][j - 1] + 1);
		}
	return (arr[len1][len2]);
}

int main(void)
{
	std::string str1;
	std::string str2;

	std::getline(std::cin, str1);
	std::getline(std::cin, str2);
	std::cout << solve(str1, str2) << std::endl;
	return (0);
}
