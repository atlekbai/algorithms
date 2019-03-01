typedef struct	s_calc
{
	int		n; // number of valid numbers
	int		o; // number of valid ops
	int		m; // max number of taps
	bool	*ops;// 1 - '+', 2 - '-', 3 - '*', 4 - '/'
	int		*numbers;
	int		w; // wanted number
	
	s_calc(void){
		ops = new bool[4];
		for (int i = 0; i < 4; i++) ops[i] = false;
	}

}				t_calc;

void show_calc(t_calc calc)
{
	std::cout << calc.n << " " << calc.o << " " << calc.m << std::endl;
	for (int i = 0; i < calc.n; i++)
		std::cout << calc.numbers[i] << " ";
	std::cout << std::endl;
	for(int i = 0; i < 4; i++)
		std::cout << calc.ops[i] <<" ";
	std::cout << std::endl;
	std::cout << calc.w << std::endl;
}

int max_arr(int *arr, int n)
{
	int max = 0;
	for (int i = 0 ; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}

void show_arr(int *arr, int len)
{
	for (int i = 0; i < len; i++)
		std::cout << i << "::" << arr[i] << std::endl;
}


// function to know whether n is built from numbers of arr elems
bool contains_n(int *arr, int len, int n)
{
	int ost;
	bool contains;
	int temp = n;

	if (temp == 0)
	{
		for (int i = 0; i < len; i++)
            if (arr[i] == ost)
				return (true);
	}
	if (temp == 0) return (false);
	while (temp > 0)
	{
		ost = temp % 10;
		contains = false;
		for (int i = 0; i < len; i++)
			if (arr[i] == ost)
			{
				contains = true;
				break;
			}
		if (!contains) return (false);
		temp /= 10;
	}
	return (true);
}

int num_len(int n)
{
	int i = 0;
	if (n == 0) return (1);
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

int *fill_all(t_calc calc)
{
	// all possible numbers build from available numbers
	int len = (max_arr(calc.numbers, calc.n) - 1) * calc.n * calc.n + calc.n;
	int *all_ns = new int[len];
	int j = 0;
	for (int i = 0; i < 1000; i++) // 0...999 range
		if (contains_n(calc.numbers, calc.n, i)) all_ns[j++] = i;
	return (all_ns);
}

int min(int a, int *s)
{
	int min = 10000;
	s[4] = a;
	for (int i = 0; i < 5; i++)
		if (s[i] > 0 && s[i] < min)
			min = s[i];
	return (min);
}

int solve(t_calc calc)
{
	int	len = (max_arr(calc.numbers, calc.n) - 1) * calc.n * calc.n + calc.n;
	int *all = fill_all(calc);
	int *N = new int[1000];
	int *equal = new int[1000];

	for (int i = 0; i < 1000; i++)
	{
		N[i] = (contains_n(calc.numbers, calc.n, i)) ? num_len(i) : 0;
		equal[i] = (contains_n(calc.numbers, calc.n, i)) ? 0 : 1;
	}
	for (int i = 0; i < 1000; i++)
	{
		if (equal[i] == 0) continue;
		int signs[5];
		signs[0] = -1;
		signs[1] = -1;
		signs[2] = -1;
		signs[3] = -1;
		signs[4] = -1; // slot for n[i]
		for (int j = 0; j < len; j++)
		{
			if (all[j] >= i && calc.ops[1] == true)// '-'
			{
				int sec_minus = (all[j] - i == 0) ? num_len(all[j]) : N[all[j] - i];
				if (sec_minus != 0)
					signs[1] = num_len(all[j]) + sec_minus + 1;
			}
			if (all[j] < i && calc.ops[0] == true)// '+'
			{
				int sec_plus = (i - all[j] == 0) ? num_len(all[j]) : N[i - all[j]];
				signs[0] = num_len(all[j]) + sec_plus + 1;
			} 
			if (all[j] < i && all[j] != 0 && i % all[j] == 0 && calc.ops[2] == true)// '*'
			{
				int sec_mult = (i / all[j] == 1) ? num_len(all[j]) : N[i / all[j]];
				if (all[i / all[j]] != 0)
					signs[2] = num_len(all[j]) + sec_mult + 1;
			}
			if (i != 0 && all[j] >= i && calc.ops[3] == true)// '/'
			{
				int sec_div = (all[j] / i == 1) ? num_len(all[j]) : N[all[j] / i];
				if (all[all[j] / i] != 0)
					signs[3] = num_len(all[j]) + sec_div + 1;
			}
			N[i] = min(N[i], signs);
		}
	}
	// show_arr(N, 1000);
	if (equal[calc.w] == 1) return (N[calc.w] + 1);
	return (N[calc.w]);
}