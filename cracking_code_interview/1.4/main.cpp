/*
  Write a method to decide if two strings are anagrams or not
*/

#include <iostream>

bool solve(char *s1, char *s2)
{
	int num[256] = {};
	int len = strlen(s1);
	if (len != strlen(s2))
		return (false);

	for (int i = 0; i < len; i++)
		num[s1[i]]++;
	for (int i = 0; i < len; i++)
	{
		num[s2[i]]--;
		if (num[s2[i]] < 0) return (false);
	}
	return (true);
}

int	main(int ac, char **av)
{
	if (ac != 3) return (0);
	bool res = solve(av[1], av[2]);
	std::cout << (res ? "Yes" : "No") << std::endl;
	return (0);
}
