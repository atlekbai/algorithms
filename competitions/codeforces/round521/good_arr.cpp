// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   good_arr.cpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 17:27:41 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 17:43:46 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <map>

void solve(int *a, int n)
{
	std::vector<int> v;
	std::map<int, bool> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		m.insert(std::pair<int, bool>(a[i], true));
		sum += a[i];
	}
	for (int i = 0; i < n; i++)
	{
		// std::cout << "--------" << std::endl;
		int res = sum - a[i];
		// std::cout << a[i] << ":: " << sum - a[i] << std::endl;
		
		// std::cout << "num? " << res / 2 << std::endl;
		// std::cout << "m? " << m[res / 2] << std::endl;

		if (res % 2 == 0 && res / 2 != a[i] && m[res / 2])
			v.push_back(i);
		// std::cout << "--------" << std::endl;
	}
	std::cout << v.size() << std::endl;
	for (int i = 0; i < v.size(); i++)
		std::cout << v[i] + 1 << " ";
	std::cout << std::endl;
}

int main(void)
{
	int n;
	int a[200000];

	std::cin >> n;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	solve(a, n);
	return (0);
}
