/*
  Write a method to replace all spaces in a string with ‘%20’
*/

#include <iostream>

char *solve(char *str)
{
	int spaces = 0;
	int len = strlen(str);
	int j = 0;
	for (int i = 0; i < len; i++)
		spaces++;
	len = spaces * 2;
	char *res = new char(len);
	for (int i = 0; i < len; i++)
	{
		if (str[j] == 32)
		{
			res[i++] = '%';
			res[i++] = '2';
			res[i] = '0';
		}
		else
			res[i] = str[j];
		j++;
	}
	return (res);
}

int	main(int ac, char **av)
{
	if (ac != 2) return (0);
	char *res = solve(av[1]);
	std::cout << res << std::endl;
	return (0);
}
