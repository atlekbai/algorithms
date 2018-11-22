/*
  Write code to reverse a C-Style String (C-String means that “abcd” is represented as
  five characters, including the null character)
*/

#include <iostream>

char *solve(char *str)
{
	char tmp;
	int i = 0;
	int j = strlen(str) - 1;

	while (i < j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}

int main(int ac, char **av)
{
	if (ac != 2) return (0);
	char* res;

	res = solve(av[1]);
	std::cout << res << std::endl;
	return (0);
}
