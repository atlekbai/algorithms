/*
  Assume you have a method isSubstring which checks if one word is a substring of
  another Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
  only one call to isSubstring (i e , “waterbottle” is a rotation of “erbottlewat”)
*/

#include <iostream>

bool solve(std::string s1, std::string s2)
{
	if (s1.length() != s2.length())
		return (false);
	std::string s1s1 = s1 + s1;
	if (s1s1.find(s2) != std::string::npos)
		return (true);
	return (false);
}

int main(int ac, char **av)
{
	if (ac != 3) return (0);
	bool res;

	res = solve(av[1], av[2]);
	std::cout << (res ? "Yes" : "No") << std::endl;
	return (0);
}
