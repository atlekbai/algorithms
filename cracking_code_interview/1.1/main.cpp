/* 
   Implement an algorithm to determine if a string has all unique characters.
   What if you can not use additional data structures?
*/

#include <iostream>
#include <map>

// Map Solution
int	solve_via_map(char *str)
{
	std::map<char, int> m;

	for (int i = 0; i < strlen(str); i++)
		if (m.find(str[i]) == m.end())
			m[str[i]] = 1;
		else
			m[str[i]]++;
	for (auto const &x: m)
		if (x.second != 1)
			return (0);
	return (1);
}

// Loops Solution
int solve_via_loops(char *str)
{
	int s;

	for (int i = 0; i < strlen(str); i++)
	{
		s = 0;
		for (int j = 0; j < strlen(str); j++)
			if (i != j && str[i] == str[j])
				s++;
		if (s != 0)
			return (0);
	}
	return (1);
}

// Genuine solution
int solve_genuine(char *str)
{
	// Need only 1 entry of char, if char already met, than return false
	bool contain[256] = {};

	for (int i = 0; i < strlen(str); i++)
	{
		if (contain[str[i]] == true) return (0);
		contain[str[i]] = true;
	}
	return (1);
}

int solve_via_bits(char *str)
{
	// Only a-z
	int checker = 0;
	// checker contains every element as 1111100001 - where each index refers to char in str
	int value;

	for (int i = 0; i < strlen(str); i++)
	{
		value = str[i] - 'a';
		if ((checker & (1 << value)) > 0) return (0);
		checker |= (1 << value);
	}
	return (1);
}

int main(int ac, char **av)
{
	if (ac != 2) return (0);
	int res;

	// Map solution
	res = solve_via_map(av[1]);
	std::cout << "Map: " << (res == 1 ? "Yes" : "No") << std::endl;

	// Only using loop solution
	res = solve_via_loops(av[1]);
	std::cout << "Loops:" << (res == 1 ? "Yes" : "No") << std::endl;

	// Using bool array
	res = solve_genuine(av[1]);
	std::cout << "Bool arr:" << (res == 1 ? "Yes" : "No") << std::endl;

	// Using bits
	res = solve_via_bits(av[1]);
	std::cout << "Bits:" << (res == 1 ? "Yes" : "No") << std::endl;
	return (0);
}
