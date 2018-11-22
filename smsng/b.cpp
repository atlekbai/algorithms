// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   b.cpp                                              :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/18 15:22:47 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/18 15:51:56 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

#define OPEN 1
#define CLOSE 2
#define ll long long
ll t[100001];
ll m[100001];

ll solve(ll *a, ll *b, ll n)
{
	ll i = 0;
	ll j = 0;
	ll k = 0;

	while (i < n && j < n)
	{
		if (b[j] <= a[i])
		{
			t[k] = b[j++];
			m[k] = CLOSE;
		}
		else
		{
			t[k] = a[i++];
			m[k] = OPEN;
		}
		k++;
	}
	for (ll s = i; s < n; s++)
	{
		t[k] = a[s];
		m[k] = OPEN;
		k++;
	}
	for (ll s = j; s < n; s++)
	{
		t[k] = b[s];
		m[k] = CLOSE;
		k++;
	}
/*
	for (ll i = 0; i < 2 * n - 1; i++)
	{
		if (m[i] == OPEN && m[i + 1] == CLOSE)
		{
			ans++;
			
		}

	}
*/
	std::set<ll> l;
	for (ll i = 0; i < 2 * n - 1; i++)
		if (m[i] == OPEN && m[i + 1] == CLOSE)
		{
			l.insert(t[i]);
			l.insert(t[i + 1]);
		}
	return ((ll)l.size());
}

ll n;
ll a[100001];
ll b[100001];

int main(void)
{
	std::cin >> n;
	for (ll i = 0; i < n; i++)
		std::cin >> a[i] >> b[i];
	std::sort(a, a + n);
	std::sort(b, b + n);
	std::cout << solve(a, b, n) << std::endl;
	return (0);
}
