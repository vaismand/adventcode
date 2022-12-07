#include "get_next_line.h"

int ft_strcmp(char *s1, char *s2)
{
	int i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			if (s1[i] == s2[j])
			{
				return (s1[i]);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_correctnum(int num)
{
	if (num > 97 && num < 123)
		return (num - 96);
	else if (num > 64 && num < 91)
		return (num - 38);
	else
		return (num);
}

int	main(void)
{
	char	*line;
	char	*line_1;
	char	*line_2;
	static int		number = 0;
	int		i = 1;
	int		fd1 = open("day3.txt", O_RDONLY);
	while (i <= 300)
	{
		line = get_next_line(fd1);
		line_1 = ft_strncpy(line);
		line_2 = ft_strrncpy(line);
		number = number + ft_correctnum(ft_strcmp(line_1, line_2));
		i++;
	}
	printf("%d\n", number);
}
