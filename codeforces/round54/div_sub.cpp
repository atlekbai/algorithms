// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   div_sub.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 17:10:25 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/12 17:53:07 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <math.h>

long long get_prime(long long n)
{
	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
			return (i);
	}
	return (n);
}

long long solve(long long n)
{
	long long res = 0;
	long long  tmp;
	while (n > 0)
	{
		long long prime = get_prime(n);
		tmp = n / prime;
//		std::cout << "n: " << n << ", prime: " << prime << " tmp: " << tmp << std::endl;
		if (prime % 2 == 0)
		{
			n -= prime * tmp;
			res += tmp;
		}
		else
		{
			n -= prime;
			res ++;
		}
	}
	return (res);
}

int main(void)
{
	long long n;
	long long res = 0;
	std::cin >> n;
	res = solve(n);
	std::cout << res << std::endl;
	return (0);
}
