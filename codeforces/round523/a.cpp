// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   a.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/22 17:45:30 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/22 17:45:37 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#define ll long long

ll n, S;
// ll arr[1000000001];

int solve()
{
	// for (int i = 1; i <= n; i++)
	// 	arr[i] = 1;
	// for (int i = 1; i <= S; i++)
	// {
	// 	if (arr[i] == 0)
	// 	{
	// 		int best = 2147483647;
	// 		for (int j = 1; j <= n; j++)
	// 			if (i - j >= 0 && arr[i - j] + 1 < best)
	// 				best = arr[i - j] + 1;
	// 		arr[i] = best;
	// 	}
	// }
	// return (arr[S]);
	int ful = S / n;
	int lac;
	if (S - ful * n == 0)
		lac = 0;
	else
		lac = (S - ful * n) <= n ? 1 : (S - ful) % n;
	return (ful + lac);
}

int main(void)
{
	std::cin >> n >> S;
	std::cout << solve() << std::endl;
	return (0);
}