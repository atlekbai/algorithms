#include <stdio.h>

#define MAX_NUM 1000
#define MAX_DIG 10
#define OPS_ARR_SIZE 5
#define MAX_OPS 9
#define MAX_PRESS 20
#define MIN(x,y) ((x < y) ? (x) : (y))


void	init_vect(int *vect, int limit, int value)
{
	for (int i = 0; i < limit; i++)
		vect[i] = value;
}

void	read_input_data(int *num_dig, int *num_ops, int *num_press,
			int *tgt_num, int *digs, int *ops)
{
	int buf, i = 0;

	scanf("%d %d %d", num_dig, num_ops, num_press);
	for (i = 0; i < *num_dig; i++)
	{
		scanf("%d", &buf);
		digs[buf] = 1;
	}
	for (i = 0; i < *num_ops; i++)
	{
		scanf("%d", &buf);
		ops[buf] = 1;
	}
	scanf("%d", tgt_num);	
}

void	fill_no_ops_nums(int *nums, int *digs)
{
	for (int i = 0; i < MAX_DIG; i++)
	{		
		if (!digs[i])
			continue;
		nums[i] = 1;
		for (int j = 0; j < MAX_DIG; j++)
		{
			if (!digs[j])
				continue;
			if (2 < nums[i * 10 + j])
				nums[i * 10 + j] = 2;
			for (int k = 0; k < MAX_DIG; k++)
			{
				if (!digs[k])
					continue;
				if (3 < nums[i * 100 + j * 10 + k]) 
					nums[i * 100 + j * 10 + k] = 3;
			}
		}
	}
}

void	fill_ops_nums(int *nums, int *ops)
{
	int index = 0, presses = 0;

	for (int i = 0; i < MAX_NUM; i++)
	{
		if (nums[i] == 1<<10)
			continue;
		for (int j = i; j < MAX_NUM; j++)
		{
			if (nums[j] == 1<<10)
				continue;
			presses = nums[i] + nums[j] + 1;
			if (ops[1])
			{
				index = i + j;
				if (index > -1 && index < MAX_NUM && presses < nums[index])
					nums[index] = presses;
			}
			if (ops[2])
			{
				index = j - i;
				if (index > -1 && index < MAX_NUM && presses < nums[index])
					nums[index] = presses;
			}
			if (ops[3])
			{
				index = i * j;
				if (index > -1 && index < MAX_NUM && presses < nums[index])
					nums[index] = presses;
			}
			if (ops[4] && i > 0)
			{
				index = j / i;
				if (index > -1 && index < MAX_NUM && presses < nums[index])
					nums[index] = presses;
			}
		}
	}
}

int		main(int ac, char **av)
{
	freopen(av[1], "r", stdin);

	int num_dig = 0, num_ops = 0, num_press = 0, tgt_num = 0;
	int digs[MAX_DIG], ops[OPS_ARR_SIZE], nums[MAX_NUM];
	init_vect(digs, MAX_DIG, 0);
	init_vect(ops, OPS_ARR_SIZE, 0);
	init_vect(nums, MAX_NUM, 1<<10);
	read_input_data(&num_dig, &num_ops, &num_press, &tgt_num, digs, ops);

	fill_no_ops_nums(nums, digs);
	if (nums[tgt_num] != 1<<10 && nums[tgt_num] <= num_press)
	{
		printf("%d\n", nums[tgt_num]);
		return (0);
	}
	for (int i = 0; i < MAX_OPS + 1; i++)
		fill_ops_nums(nums, ops);

	if (nums[tgt_num] != 1<<10 && nums[tgt_num] < num_press)
	{
		printf("%d\n", nums[tgt_num] + 1);
		return (0);
	}
	printf("-1\n");
	return (0);
}