// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/15 20:57:19 by atlekbai          #+#    #+#             //
//   Updated: 2018/10/15 21:02:52 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>
#include <stack>

struct Tower
{
	std::stack<int>	s;
	int				index;

	Tower(void){}
	Tower(int i) : index(i){}
	~Tower(void){}
};

int		main(void)
{
	int		n = 5;
	Tower	*tower = new Tower[n];

	for (int i = 0; i < 3; i++)
		tower[i] = Tower(i);
	for (int i = n; i > 0; i--)
		tower[0].s.push(i);
	return (0);
}
