#include "get_next_line.h"

int	atoi_str(char *line)
{
	int i;
	int j;
	int k;
	int num;
	int sign;

	i = 0;
	j = 0;
	k = 0;
	num = 0;
	while (line[i] < '0' || line[i] > '9' || line[i] == '\0' || line[i] == ' ')
	{
		if (line[i] == '-')
			sign = -1;
		i++;
	}
	if (line[i] >= '0' && line[i] <= '9')
	{
		j = i;
		while (line[j] >= '0' && line[j] <= '9')
		{
			j++;
			k++;
		}
		while (k > 0)
		{
			num = num * 10 + (line[i] - '0');
			i++;
			k--;
		}
	}
	return (num);
}

int	check_condition(char *line) 
{
	int i = 0;
	if (line[i] == '$' && line[i + 1] == ' ' && line[i + 2] == 'c' && line[i + 3] == 'd')
	{
		return (1);
	}
	else if (line[i] == '$' && line[i + 1] == ' ' && line[i + 2] == 'l' && line[i + 3] == 's')
	{
		return (2);
	}
	else if(line[i] >= '0' && line[i] <= '9')
	{
		
		return (3);
	}
	else if ( line[i] == 'd' && line[i + 1] == 'i' && line[i + 2] == 'r')
	{
		return (4);
	}
	else 
	{
		return (0);
	}
}


int	main(void)
{
	char	*line;
	char	**arr;
	int		result = 0;
	int		final_result = 0;
	int		i = 1;
	int		fd1 = open("day7.txt", O_RDONLY);
	while (i <= 40)
	{
		line = get_next_line(fd1);
		if (check_condition(line) == 2)
		{
			line = get_next_line(fd1);
			while (check_condition(line) == 3 || check_condition(line) == 4)
			{
				if (check_condition(line) == 3)
				{
					result = result + atoi_str(line);
				}
				line = get_next_line(fd1);
			}
			if (result < 100000)
			{
				final_result = final_result + result;
			}
		}
		i++;
	}
	printf("%d\n", final_result);
}