// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/18 19:55:28 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/18 19:55:35 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#define ll long long

class Rabin
{
private:
	ll p;
	ll x;
public:
	Rabin(void)
	{
		p = 1000000007;
		x = rand() % p;
	}

	std::vector<int>	search(std::string T, std::string P)
	{
		std::vector<int> result;
		ll current = hashFunction(P);
		ll *H = precomputeHashes(T, P.length());
		for (int i = 0; i <= T.length() - P.length(); i++)
		{
			if (current != H[i])
				continue ;
			if (T.substr(i, i + P.length()) == P)
				result.push_back(i);
		}
		std::cout << "size: " << result.size() << std::endl;
		return (result);
	}

	int		hashFunction(std::string S) const
	{
		unsigned ll res = 0;
		for (int i = S.size() - 1; i >= 0; --i)
			res = (res * x + S[i]) % p;
		return (res);
	}

	ll		*precomputeHashes(std::string text, int lenPattern)
	{
		int last = text.length() - lenPattern;
		ll *H = new ll[last + 1];
		std::string S = text.substr(last);
		int y = 1;
		H[last] = hashFunction(S);
		for (int i = 0; i < lenPattern; i++)
			y = (y * x) % p;
		for (int i = last - 1; i >= 0; i--)
			H[i] = (x * H[i + 1] + text[i] - y * text[i + lenPattern]) % p;
		return (H);
	}
};


int main(void)
{
	Rabin r;
	std::string text, pattern;
	std::getline(std::cin, pattern);
	std::getline(std::cin, text);
	std::vector<int> result = r.search(text, pattern);
	for (int i = 0; i < result.size(); i++)
		std::cout << result[i] << " ";
	std::cout << std::endl;
	return (0);
}