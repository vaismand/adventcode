#include "get_next_line.h"

int	check_index(char *line)
{
	int i;
	char *str = line;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] != str[i + 1]) && (str[i] != str[i + 2]) && (str[i] != str[i + 3])
		&& (str [i + 1] != str[i + 2]) && (str[i + 1] != str[i + 3]) && (str[i + 2] != str[i + 3]))
		{
			return (i + 4);
		}
		i++;
	}
	return (i);
}


int	main(void)
{
	char	*line;
	int		chr_index = 0;
	int		fd1 = open("day6.txt", O_RDONLY);
	line = get_next_line(fd1);
	chr_index = check_index(line);
	printf("%d\n", chr_index);
}
