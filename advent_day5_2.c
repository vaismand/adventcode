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

int	atoi_src(char *line)
{
	int num;
	int len;

	len = ft_strlen(line) - 8; //change to "-7" on linux
	num = line[len] - '0';
	return (num);
}

int	atoi_dst(char *line)
{
	int num;
	int len;

	len = ft_strlen(line) - 3; //change to "-2" on linux
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
	char	*tower0[60] = {"G", "D", "V", "Z", "J", "S", "B"};
	char	*tower1[60] = {"Z", "S", "M", "G", "V", "P"};
	char	*tower2[60] = {"C", "L", "B", "S", "W", "T", "Q", "F"};
	char	*tower3[60] = {"H", "J", "G", "W", "M", "R", "V", "Q"};
	char	*tower4[60] = {"C", "L", "S", "N", "F", "M", "D"};
	char	*tower5[60] = {"R", "G", "C", "D"};
	char	*tower6[60] = {"H", "G", "T", "R", "J", "D", "S", "Q"};
	char	*tower7[60] = {"P", "F", "V"};
	char	*tower8[60] = {"D", "R", "S", "T", "J"};
	char	*temp_tower[60] = {NULL};
	char	**towers[10] = {tower0, tower1, tower2, tower3, \
		tower4, tower5, tower6, tower7, tower8, temp_tower};
	char	*temp;
	int		i = 1;
	int		fd1 = open("day5.txt", O_RDONLY);
	int		moves;
	int		size;
	int		size2;
	int		size3;
	int		src;
	int		dst;
	while (i <= 502)
	{
		line = get_next_line(fd1);
		moves = atoi_str(line);
		src = atoi_src(line) - 1;
		dst = atoi_dst(line) - 1; 
		size = tower_last_index(towers[src]);
		size2 = tower_last_index(towers[dst]);
		size3 = tower_last_index(towers[9]);
		while (moves != 0)
		{
			temp = towers[src][size - 1];
			towers[9][size3] = temp;
			towers[src][size - 1] = NULL;
			size3++;
			moves--;
			size--;
		}
		moves = atoi_str(line);
		while (moves != 0)
		{
			temp = towers[9][size3 - 1];
			towers[dst][size2] = temp;
			towers[9][size3 - 1] = NULL;
			size3--;
			moves--;
			size2++;
		}
		i++;
	}
	for (int i = 0; i < 10; i++)
	{
		printf("Tower %d: ", i + 1);
		for (int j = 0; towers[i][j] != NULL; j++)
			printf("%s ", towers[i][j]);
		printf("\n");
	}
}