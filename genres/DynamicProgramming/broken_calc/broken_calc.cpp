// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   broken_calc.cpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <marvin@42.fr>                    +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/09/15 21:00:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/09/16 14:27:32 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

#define MAX_NUM 1000
#define OPS 4
#define DIGIT_MAX 10

typedef struct	s_calc
{
	int		n; // number of valid numbers
	int		o; // number of valid ops
	int		m; // max number of taps
	bool	ops[OPS];// 1 - '+', 2 - '-', 3 - '*', 4 - '/'
	int		N[MAX_NUM];
	int		nums[DIGIT_MAX];
	int		w; // wanted number
}				t_calc;

// function to know whether n is built from numbers of arr elems
bool contains_n(int *arr, int len, int n)
{
	int ost;
	bool contains;
	int temp = n;
	
	do
	{
		ost = temp % 10;
		contains = false;
		for (int i = 0; i < len; i++)
			if (arr[i] == ost)
			{
				contains = true;
				break;
			}
		if (!contains) return (false);
		temp /= 10;
	} while (temp > 0);
	return (true);
}

int num_len(int n)
{
	int i = 0;
	if (n == 0) return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

void fill_calc(t_calc *calc)
{
	for (int i = 0; i < MAX_NUM; i++)
		if(contains_n(calc->nums, calc->n, i))
			calc->N[i] = num_len(i);
		else
			calc->N[i] = -1;
}

void solve(t_calc *calc)
{
	int presses = 0;
	int index = 0;
	for (int i = 0; i < MAX_NUM; i++)
	{
		if (calc->N[i] == -1) continue;
		for (int j = 0; j < MAX_NUM; j++)
		{
			if (calc->N[j] == -1) continue;
			presses = calc->N[i] + calc->N[j] + 1;
			if (calc->ops[0])
			{
				index = i + j;
				if (index < MAX_NUM && (calc->N[index] == -1 || presses < calc->N[index]))
					calc->N[index] = presses;
			}
			if (calc->ops[1])
			{
				index = i - j;
				if (index >= 0 && index < MAX_NUM && (calc->N[index] == -1 || presses < calc->N[index]))
					calc->N[index] = presses;
			}
			if (calc->ops[2])
			{
				index = i * j;
				if (index < MAX_NUM && (calc->N[index] == -1 || presses < calc->N[index]))
					calc->N[index] = presses;
			}
			if (calc->ops[3] && j != 0)
			{
				index = i / j;
				if (index < MAX_NUM && (calc->N[index] == -1 || presses < calc->N[index]))
					calc->N[index] = presses;
			}
		}
	}
}

int main(int ac, char **av)
{
	t_calc calc;
	
	freopen(av[1], "r", stdin);
	std::cin >> calc.n;
	std::cin >> calc.o;
	std::cin >> calc.m;
	for (int i = 0; i < calc.n; i++)
		std::cin >> calc.nums[i];
	for (int i = 0; i < calc.o; i++)
	{
		int c;
		std::cin >> c;
		calc.ops[c - 1] = true;
	}
	std::cin >> calc.w;

	fill_calc(&calc);
	if (calc.N[calc.w] <= calc.m && calc.N[calc.w] != -1)
	{
		std::cout << calc.N[calc.w] << std::endl;
		return (0);
	}
	for (int i = 0; i < DIGIT_MAX + 1; i++)
		solve(&calc);
	if (calc.N[calc.w] <= calc.m && calc.N[calc.w] != -1)
	{
		std::cout << calc.N[calc.w] + 1 << std::endl;
		return (0);
	}
	std::cout << "-1" << std::endl;
	return (0);
}
