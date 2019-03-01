// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   cut_out.cpp                                        :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/16 17:57:37 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/16 18:03:38 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

void solve(int *a, int n, int k)
{
	std::map<int, int> m;
	std::map<int, int> c;
	std::vector<int> v;
	for (int i = 0; i < n; i++)
	{
		if (m[a[i]])
			m[a[i]]++;
		else
			m[a[i]] = 1;
	}
	auto cmp = [](std::pair<int,int> & a1, std::pair<int,int> & b1) 
	{ 
	     return a1.second != b1.second?  a1.second < b1.second : a1.first < b1.first;
	};
	std::sort(m.begin(), m.end(), cmp);
	// for (int i = 0; i < k; i++)
	// {
	// 	auto p = m.begin();
	// 	for (auto i = m.begin(); i != m.end(); i++)
	// 		if (i->second > p->second)
	// 		{
	// 			p = i;
	// 		}
	// 	v.push_back(p->first);
	// 	if (c[p->first])
	// 		c[p->first]++;
	// 	else
	// 		c[p->first] = 1;
	// 	p->second /= (c[p->first] + 1);
	// }
	// for (int i = 0; i < v.size(); i++)
	// 	std::cout << v[i] << " ";
	// std::cout << std::endl;
}

int main(void)
{
	int n;
	int k;
	int a[200000];

	std::cin >> n;
	std::cin >> k;
	for (int i = 0; i < n; i++)
		std::cin >> a[i];
	solve(a, n, k);
}
