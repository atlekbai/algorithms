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
#define ll long long
using namespace std;

ll n, m, used[111111];

struct sgm
{
	ll l;
	ll r;
	ll pn;
};

ll cmp(sgm a, sgm b)
{
	return (a.r - a.l < b.r - b.l);
}


bool iwinde(sgm a, sgm b)
{
	return (b.l <= a.l && b.r >= a.r);
}

bool intl(sgm a, sgm b)
{
	if(a.r >= b.l && a.r <= b.r)
		return (true);
	else if(a.l >= b.l && a.r <= b.r)
		return (true);
	return (false);
}

sgm a[111111];
ll ans;

int main ()
{
	cin >> n;
	for (ll i = 0; i < n; ++i)
		cin >> a[i].l >> a[i].r;
	sort(a, a + n, cmp);
	//cout << endl;
//	for (ll i = 0; i < n; ++i)
//		cout << a[i].l << " " << a[i].r << '\n';
	for (ll i = 0; i < n - 1; ++i)
	{
		for (ll j = i + 1; j < n; ++j)
		{
			//cout << ">" << i<< " ) "<< a[i].l << " " << a[i].r << "::" << j<< " ) " << a[j].l << " " << a[j].r << ">\n";
			//cout << used[i] << " " << used[j] << "::" << (a[j].l <= a[i].l )<< "_" << (a[j].r >= a[i].r) << endl;
			if (used[i] == 0 && used[j] == 0 && iwinde(a[i], a[j]))
			{
			//	cout << "@" << i<< " ) "<< a[i].l << " " << a[i].r << " " << j<< " ) " << a[j].l << " " << a[j].r << "@\n";
				used[i] = 2;
				used[j] = 2;
				ans += 2;
			}
			else if (used[i] == 2 && used[j] == 0 && iwinde(a[i], a[j]))
			{
			//	cout << "#" << i<< " ) "<< a[i].l << " " << a[i].r << " " << j<< " ) " << a[j].l << " " << a[j].r << "#\n";
				used[j] = 2;
			}		
		}
	}
	


	for (ll i = 0; i < n - 1; ++i)
	{
		for (ll j = i + 1; j < n; ++j)
		{
			//cout << ">" << i<< " ) "<< a[i].l << " " << a[i].r << "::" << j<< " ) " << a[j].l << " " << a[j].r << ">\n";
			//cout << used[i] << " " << used[j] << "::" << (a[j].l <= a[i].l )<< "_" << (a[j].r >= a[i].r) << endl;
			if(used[i] <= 1 && used[j] <= 1 && intl(a[i], a[j]))
			{
			//	cout << "!" << i<< ") "<< a[i].l << " " << a[i].r << " " << j<< ") " << a[j].l << " " << a[j].r << "!\n";
				used[i]++;
				used[j]++;
				ans++;
			}
			else if(used[i] <= 2 && used[j] <= 1 && intl(a[i], a[j]))
				used[j]++;
		}
	}
	

	for (ll i = 0; i < n; ++i)
	{
		if(used[i] == 0)
			ans += 2;
		else if(used[i] == 1)
			ans++;
	}
	cout << ans;
	return (0);
}