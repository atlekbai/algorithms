// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   math.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/14 18:46:49 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/14 18:48:44 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <math.h>
#define MAX 5200

void solve(int n, int *arr, int *val)
{
	for (int i = 2; i <= sqrt(MAX); i++)
		if (i * i <= MAX)
		{
			if (sqrt(i) == round(sqrt(i)))
			{
				arr[i * i] = arr[i] + 1;
				val[i * i] = val[i];
			}
			else
			{
				arr[i * i] = 1;
				val[i * i] = i;
			}
		}
	for (int y = 0; y < 10; y++)
		for (int i = MAX; i >= 0; i--)
		{
			if (arr[i] != 0)
				for (int j = 2; j < (int)sqrt(i); j++)
				{
					if (i % j == 0)
					{
						if (arr[i / j] == 0)
						{
							arr[i / j] = arr[i] + 1;
							val[i / j] = val[i];
						}
						else if (val[i] < val[i / j])
						{
							arr[i / j] = arr[i] + 1;
							val[i / j] = val[i];
						}
					}
				}
		}
	for (int i = MAX; i >= 0; i--)
		if (sqrt(i) == round(sqrt(i)) && val[(int)sqrt(i)] < val[i])
		{
			arr[i] = arr[(int)sqrt(i)] + 1;
			val[i] = val[(int)sqrt(i)];
		}
		else if (val[i] == i)
		{
			arr[i] = 0;
			val[i] = 0;
		}
}

int main(void)
{
	int arr[MAX + 1] = {};
	int val[MAX + 1] = {};
	int n;
	int res = 0;
	std::cin >> n;
	solve(n, arr, val);
	std::cout << val[n] << " " << arr[n] << std::endl;
	return (0);
}
