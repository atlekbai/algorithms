/*
  Design an algorithm and write code to remove the duplicate characters in a string
  without using any additional buffer. NOTE: One or two additional variables are fine.
  An extra copy of the array is not
  FOLLOW UP
  Write the test cases for this method
*/

#include <iostream>

char *solve(char *str)
{
	bool contains;
	for (int i = 1; i < strlen(str); i++)
	{
		contains = false;
		for (int j = 0; j < i; j++)
			if (str[i] == str[j])
			{
				contains = true;
				break;
			}
		if (contains)
		{	
			for (int j = i; j < strlen(str); j++)
				str[j] = str[j + 1];
			i--;
		}
	}
	return (str);
}

char *solve_simple(char *str)
{
	if (strlen(str) <= 2) return (str);
	int len = strlen(str);
	int tail = 1;
	int j;
	for (int i = 0; i < len; i++)
	{
		for (j = 0; j < tail; j++)
			if (str[i] == str[j]) break;
		if (j == tail)
		{
			str[tail] = str[i];
			tail++;
		}
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 2) return (0);
	char *res;

	res = solve(av[1]);
	std::cout << res << std::endl;

	res = solve_simple(av[1]);
	std::cout << res << std::endl;
	return (0);
}
