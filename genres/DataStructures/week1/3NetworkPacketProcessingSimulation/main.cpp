// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/12/09 13:30:35 by atlekbai          #+#    #+#             //
//   Updated: 2018/12/09 14:20:17 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <vector>
#include <list>

struct package
{
	int arrival;
	int size;
	int	finish;
};

class Buffer
{
public:
	int lastFinish = 0;
	std::list<package>	buf;
	std::vector<int>	output;
	int	space;

	Buffer(int s) : space(s){}
	void print(void) const
	{
		std::cout << "space: " << space << std::endl;
		std::cout << "-------" << std::endl;
		for (auto b: buf)
		{
			std::cout << "arrival: " << b.arrival << std::endl;
			std::cout << "size: " << b.size << std::endl;
			std::cout << "finish: " << b.finish << std::endl;
			std::cout << std::endl;
		}
	}
	
	void printOutput(void) const
	{
		for (int i = 0; i < output.size(); i++)
			std::cout << output[i] << std::endl;
	}

	void process(package p)
	{
		updateBuffer(p);
		if (space == 0)
		{
			output.push_back(-1);
			return ;
		}
		if (buf.empty())
		{
			lastFinish = p.arrival + p.size;
			p.finish = lastFinish;
			output.push_back(p.arrival);
		}
		else
		{
			output.push_back(lastFinish);
			lastFinish += p.size;
			p.finish = lastFinish;
		}
		buf.push_back(p);
		space--;
	}
	void updateBuffer(package p)
	{
		while (!buf.empty() && buf.front().finish <= p.arrival)
		{
			space++;
			buf.pop_front();
		}
	}
};

int main(void)
{
	std::vector<package>		net;
	package	p;
	int		S;
	int		n;
	std::cin >> S >> n;
	Buffer b(S);
	for (int i = 0; i < n; i++)
	{
		std::cin >> p.arrival >> p.size;
		p.finish = 0;
		net.push_back(p);
		b.process(net[i]);
	}
	b.printOutput();
	return (0);
}
