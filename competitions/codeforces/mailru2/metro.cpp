// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/10 16:40:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/10 17:00:39 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <list>

bool solve(int *a, int *b, int n, int s, std::list<std::pair<int, int>> path)
{
	std::list<std::pair<int, int>>::iterator it = path.begin();
	if (a[0] == s)
		return (true);
	if (a[0] == 0)
		return (false);
	int j = 1;
	while (it != path.end())
	{
		if (j == s && it->first == 1)
			return (true);
		if (j > s)
			break ;
		j++;
		it++;
	}
	if (it->first == 0 || it->second == 0)
		return (false);
	while (it != path.begin())
	{
		if (j == s && it->second == 1)
			return (true);
		it--;
		j--;
	}
	return (false);
}

int main(void)
{
	int n;
	int s;
	int a[1000];
	int b[1000];
	std::list<std::pair<int, int>> path;
	std::cin >> n;
	std::cin >> s;
	for (int i = 0; i < n; i++)
	{
		std::cin >> a[i];
		path.push_back(std::make_pair(a[i], 0));
	}
	std::list<std::pair<int, int>>::iterator it = path.begin();
	for (int i = 0; i < n; i++)
	{
		std::cin >> b[i];
		it->second = b[i];
		it++;
	}
	std::cout << ((solve(a, b, n, s, path) == 1) ? "YES" : "NO") << std::endl;
	return (0);
}
