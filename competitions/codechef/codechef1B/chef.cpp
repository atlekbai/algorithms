#include <iostream>

int main(void)
{
	int t;
	int j;
	std::string year;
	std::string years[] = {"2010", "2015", "2016", "2017", "2019"};
	std::cin >> t;
	for (int i = 0; i < t; i++)
	{
		std::cin >> year;
		for (j = 0; j < 5; j++)
			if (year == years[j])
			{
				std::cout << "HOSTED" << std::endl;
				break ;
			}
		if (j == 5)
			std::cout << "NOT HOSTED" << std::endl;
	}
	return (0);
}
