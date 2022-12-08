#include "get_next_line.h"

int	check_index(char *line)
{
	int i;
	int j;
	int x;
	int y;
	char *str = line;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while ((str[i] != str[j]) && (j <= i + 13))
		{
			if (str[i] == str[j])
			{
				i++;
				break;
			}
			else if (j == i + 13)
			{
				x = i + 1;
				y = x + 1;
				while ((str[x] != str[y]) && (x != j))
				{
					if (str[x] == str[y])
					{
						i++;
						break;
					}
					else if ((x == (j - 1)) && (y == j))
					{
						return (j);
					}
					else if (y == j)
					{
						x++;
						y = x;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}	
	return (j);	
}


int	main(void)
{
	char	*line;
	int		chr_index = 0;
	int		fd1 = open("day6.txt", O_RDONLY);
	line = get_next_line(fd1);
	chr_index = check_index(line) + 1;
	printf("%d\n", chr_index);
}
