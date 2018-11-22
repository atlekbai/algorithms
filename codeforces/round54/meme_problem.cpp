// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   meme_problem.cpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/11/12 17:56:46 by atlekbai          #+#    #+#             //
//   Updated: 2018/11/12 18:17:07 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <math.h>
#include <iomanip>

int solve(double d, std::pair<double, double> &res)
{
	double des = (d * d) - 4 * d;
//	std::cout << des << std::endl;
	if (des < 0)
		return (0);
	else if (des > 0)
	{
		double x1 = (d + sqrt(des)) / 2;
		double x2 = (d - sqrt(des)) / 2;
		res = std::make_pair(x1, x2);
		return (1);
	}
	double x = d / 2;
	res = std::make_pair(x, x);
	return (1);
}

int main(void)
{
	int n;
	int d;
	int s;
	std::pair<double, double> res;

	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> d;
		s = solve(d, res);
		if (s == 0)
			std::cout << "N" << std::endl;
		else
			std::cout << "Y " << std::setprecision(13) << res.first << " " << res.second << std::endl;
	}
	return (0);
}
