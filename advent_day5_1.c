#include "get_next_line.h"

int	ft_power(int nb, int power)
{
	int i;
	int result;

	i = 0;
	result = 1;
	if (power < 0)
		return (0);
	while (i < power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

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

int	atoi_src(char *line)
{
	int num;
	int len;

	len = ft_strlen(line) - 8;
	num = line[len] - '0';
	return (num);
}

int	atoi_dst(char *line)
{
	int num;
	int len;

	len = ft_strlen(line) - 3;
	num = line[len] - '0';
	return (num);
}

int	get_next_movement(const char *str)
{
	int moves;
	int src;
	int dst;
	moves = atoi(str);
	return (moves);
}


int	main(void)
{
	char	*line;
	/*char	*tower0[20] = {"B", "S", "J", "Z", "V", "D", "G"};
	char	*tower1[20] = {"P", "V", "G", "M", "S", "Z"};
	char	*tower2[20] = {"F", "Q", "T", "W", "S", "B", "L", "C"};
	char	*tower3[20] = {"Q", "V", "R", "M", "W", "G", "J", "H"};
	char	*tower4[20] = {"D", "M", "F", "N", "S", "L", "C"};
	char	*tower5[20] = {"D", "C", "G", "R"};
	char	*tower6[20] = {"Q", "S", "D", "J", "R", "T", "G", "H"};
	char	*tower7[20] = {"V", "F", "P"};
	char	*tower8[20] = {"J", "T", "S", "R", "D"};*/
	int		i;
	int		fd1;
	int		moves;
	int		src;
	int		dst;
	
	i = 1;
	fd1 = open("shipping.txt", O_RDONLY);
	while (i <= 5)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		moves = atoi_str(line);
		src = atoi_src(line);
		dst = atoi_dst(line);
		printf("%d\n", moves);
		printf("%d\n", src);
		printf("%d\n", dst);
		i++;
	}

}
