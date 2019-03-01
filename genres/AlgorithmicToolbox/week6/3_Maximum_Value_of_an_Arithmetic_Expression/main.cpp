// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/17 16:14:27 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/17 16:49:57 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include <vector>

void parse_line(std::string str, int *nums, int *ops, int &len_n, int &len_o)
{
	int op;
	for (int i = 1; i <= str.length(); i++)
		if (i % 2 == 0)
		{
			if (str[i - 1] == '+')
				op = 1;
			else if (str[i - 1] == '-')
				op = 2;
			else
				op = 3;
			ops[len_o++] = op;
		}
		else
			nums[len_n++] = str[i - 1] - '0';
}

int operate(int op, int a, int b)
{
	if (op == 1)
		return (a + b);
	else if (op == 2)
		return (a - b);
	return (a * b);
}

int ft_max(int a, int b, int c, int d)
{
	int arr[4] = {a, b, c, d};
	std::sort(arr, arr + 4);
	return (arr[3]);
}

int ft_min(int a, int b, int c, int d)
{
	int arr[4] = {a, b, c, d};
	std::sort(arr, arr + 4);
	return (arr[0]);
}

std::pair<int, int> min_and_max(int *ops, std::vector<std::vector<int> > max, std::vector<std::vector<int> > min, int i, int j)
{
	int minimum = 0;
	int maximum = 0;
	for (int k = i; k < j - 1; k++)
	{
		int a = operate(ops[k], max[i][k], max[k + 1][j]);
		int b = operate(ops[k], max[i][k], min[k + 1][j]);
		int c = operate(ops[k], min[i][k], max[k + 1][j]);
		int d = operate(ops[k], min[i][k], min[k + 1][j]);
		std::cout << a << " " << b << " " << c << " " << d << std::endl;
		maximum = ft_max(a, b, c, d);
		minimum = ft_min(a, b, c, d);
	}
	return (std::make_pair(minimum, maximum));
}

int solve(int *nums, const int n, int *ops, const int o)
{
	std::vector<std::vector<int> > min(n);
	for (int i = 0; i < n; i++)
		min[i] = std::vector<int>(n);

	std::vector<std::vector<int> > max(n);
	for (int i = 0; i < n; i++)
		max[i] = std::vector<int>(n);
	int j;

	for (int i = 0; i < n; i++)
	{
		min[i][i] = nums[i];
		max[i][i] = nums[i];
	}
	for (int s = 0; s < n; s++)
		for (int i = 0; i < n - s; i++)
		{
			j = i + s + 1;
			std::pair<int, int> min_max = min_and_max(ops, max, min, i, j);
			min[i][j] = min_max.first;
			max[i][j] = min_max.second;
		}

	std::cout << "min: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << min[i][j] << " ";
		std::cout << std::endl;
	}

	std::cout << "max: " << std::endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			std::cout << max[i][j] << " ";
		std::cout << std::endl;
	}
	return (max[0][n - 1]);
}

int main(void)
{
	std::string str;
	int nums[50];
	int ops[50];
	int len_n = 0;
	int len_o = 0;

	std::getline(std::cin, str);
	parse_line(str, nums, ops, len_n, len_o);
	std::cout << solve(nums, len_n, ops, len_o) << std::endl;

	/*for (int i = 0; i < len_n; i++)
		std::cout << nums[i] << " ";
	std::cout << std::endl;

	for (int i = 0; i < len_o; i++)
		std::cout << ops[i] << " ";
		std::cout << std::endl;*/
	return (0);
}
