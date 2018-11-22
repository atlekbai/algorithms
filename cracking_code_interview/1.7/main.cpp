/*
  Write an algorithm such that if an element in an MxN matrix is 0, its entire row and
  column is set to 0
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int main(int ac, char **av)
{
	if (ac != 3) return (0);
	srand(time(NULL));
	int n = atoi(av[1]);
	int m = atoi(av[2]);
	int arr[n][m];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = rand() % 20;
	
	// solution
	// keep rows to set to zero
	int row[1000] = {};
	// keep cols to set to zero
	int col[1000] = {};
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (arr[i][j] == 0)
			{
				row[i] = 1;
				col[j] = 1;
			}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (row[i] == 1 || col[j] == 1)
				arr[i][j] = 0;
	// solution
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			std::cout << arr[i][j] << "\t";
		std::cout << std::endl;
	}
	return (0);
}
