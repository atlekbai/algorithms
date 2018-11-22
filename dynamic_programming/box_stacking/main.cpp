// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: atlekbai <atlekbai@student.unit.ua>        +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2018/10/04 19:28:26 by atlekbai          #+#    #+#             //
//   Updated: 2018/10/04 19:51:29 by atlekbai         ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include <iostream>

// h => w => d
struct Box
{
	int h;
	int w;
	int d;
	int i;
};

int min(int a, int b)
{
	return (a < b) ? a : b;
}

int max(int a, int b)
{
	return (a > b) ? a : b;
}

int compare(Box a, Box b)
{
	return (a.w * a.d - b.w * b.d);
}

void sort(Box *box, int n, int (*f)(Box a, Box b))
{
	Box tmp;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (f(box[i], box[j]) > 0)
			{
				tmp = box[i];
				box[i] = box[j];
				box[j] = tmp;
			}
}

int solve(int n, int **arr)
{
	int index = 0;
	Box boxes[n * 3];
	for (int i = 0; i < n; i++)
	{
		boxes[index].h = arr[i][0];
		boxes[index].w = max(arr[i][1], arr[i][2]);
		boxes[index].d = min(arr[i][1], arr[i][2]);
		boxes[index].i = i;
		index++;

		boxes[index].h = arr[i][1];
		boxes[index].w = max(arr[i][0], arr[i][2]);
		boxes[index].d = min(arr[i][0], arr[i][2]);
		boxes[index].i = i;
		index++;

		boxes[index].h = arr[i][2];
		boxes[index].w = max(arr[i][0], arr[i][1]);
		boxes[index].d = min(arr[i][0], arr[i][1]);
		boxes[index].i = i;
		index++;
	}
	int len = n * 3;
	sort(boxes, len, &compare);
	int res[len];

	for (int i = 0; i < len; i++)
	{
		res[i] = boxes[i].h;
		// std::cout << res[i] << " = " << boxes[i].d * boxes[i].w  << ": " << boxes[i].d << ", "<< boxes[i].w  << std::endl;
	}

	for (int i = 1; i < len; i++)
		for (int j = 0; j < i; j++)
			if (boxes[i].w < boxes[j].w &&
				boxes[i].d < boxes[j].d &&
				res[i] < res[j] + boxes[i].h && boxes[i].i != boxes[j].i)
				res[i] = res[j] + boxes[i].h;

	int max = 0;
	for (int i = 0; i < len; i++)
		if (max < res[i])
			max = res[i];
	return (max);
}

int main(void)
{
	int n;
	int **arr = new int*[20];
	for (int i = 0; i < 20; i++)
		arr[i] = new int[3];
	std::cin >> n;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < 3; k++)
			std::cin >> arr[i][k];
	int res = solve(n, arr);
	std::cout << "result: " << res << std::endl;
	return (0);
}
