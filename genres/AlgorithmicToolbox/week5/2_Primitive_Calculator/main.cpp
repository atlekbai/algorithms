// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 23:13:16 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/13 20:25:28 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>
#include <vector>

/*
387721
*/

void backpropagate(int n, int *ans, std::list<int> &v)
{
	int min;
	v.push_front(n);
	while (ans[n] > 0)
	{
		min = n - 1;
		if (n % 2 == 0)
			min = (std::min(ans[n / 2], ans[min]) == ans[n / 2]) ? n / 2 : n - 1;
		if (n % 3 == 0)
			min = (std::min(ans[n / 3], ans[min]) == ans[n / 3]) ? n / 3 : min;
		n = min;
		v.push_front(n);
	}
}

int solve(int n, std::list<int> &v)
{
	int res = 1;
	int ans[1000001];
	int j = 0;
	std::fill(ans, ans + 1000001, 0);
	for (int i = 2; i <= n; i *= 2)
		ans[i] = ++j;
	j = 0;
	for (int i = 3; i <= n; i *= 3)
		ans[i] = ++j;
	for (int i = 4; i <= n; i++)
	{
		if (ans[i] != 0)
			continue ;
		if (i % 2 == 0 && (ans[i / 2] + 1 < ans[i] || ans[i] == 0))
			ans[i] = ans[i / 2] + 1;
		if (i % 3 == 0 && (ans[i / 3] + 1 < ans[i] || ans[i] == 0))
			ans[i] = ans[i / 3] + 1;
		if (ans[i - 1] + 1 < ans[i] || ans[i] == 0)
			ans[i] = ans[i - 1] + 1;
	}
	backpropagate(n, ans, v);
	return (ans[n]);
}

int main(void)
{
	int n;
	std::list<int> v;
	std::cin >> n;
	int res = solve(n, v);
	std::cout << res << std::endl;
	for (auto i = v.begin(); i != v.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;
	return (0);
}
