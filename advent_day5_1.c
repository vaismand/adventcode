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

	len = ft_strlen(line) - 7;
	num = line[len] - '0';
	return (num);
}

int	atoi_dst(char *line)
{
	int num;
	int len;

	len = ft_strlen(line) - 2;
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

int	tower_last_index(char **tower)
{
	int i;

	i = 0;
	while (tower[i] != NULL)
		i++;
	return (i);
}


int	main(void)
{
	char	*line;
	char	*tower0[40] = {"G", "D", "V", "Z", "J", "S", "B"};
	char	*tower1[40] = {"Z", "S", "M", "G", "V", "P"};
	char	*tower2[40] = {"C", "L", "B", "S", "W", "T", "Q", "F"};
	char	*tower3[40] = {"H", "J", "G", "W", "M", "R", "V", "Q"};
	char	*tower4[40] = {"C", "L", "S", "N", "F", "M", "D"};
	char	*tower5[40] = {"R", "G", "C", "D"};
	char	*tower6[40] = {"H", "G", "T", "R", "J", "D", "S", "Q"};
	char	*tower7[40] = {"P", "F", "V"};
	char	*tower8[40] = {"D", "R", "S", "T", "J"};
	char	**towers[9] = {tower0, tower1, tower2, tower3, \
		tower4, tower5, tower6, tower7, tower8};
	char	*temp;
	int		i = 1;
	int		fd1 = open("shipping.txt", O_RDONLY);
	int		moves;
	int		size;
	int		size2;
	int		src;
	int		dst;
	while (i <= 1)
	{
		line = get_next_line(fd1);
		moves = atoi_str(line);
		src = atoi_src(line) - 1;
		dst = atoi_dst(line) - 1;
		size = tower_last_index(towers[src]);
		size2 = tower_last_index(towers[dst]);
		while (moves != 0)
		{
			temp = towers[src][size - 1];
			towers[dst][size2++] = temp;
			towers[src][size - 1] = NULL;
			moves--;
			size--;
		}
		i++;
	}
	for (int i = 0; i < 9; i++)
	{
		printf("Tower %d: ", i + 1);
		for (int j = 0; towers[i][j] != NULL; j++)
			printf("%s ", towers[i][j]);
		printf("\n");
	}
}
