#include "get_next_line.h"

int ft_strcmp_three(char *s1, char *s2, char *s3)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	k = 0;
	while (s1[i] != '\0')
	{
		while (s2[j] != '\0')
		{
			while (s3[k] != '\0')
			{
				if (s1[i] == s2[j] && s2[j] == s3[k])
				{
					return (s1[i]);
				}
				k++;
			}
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
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
	static int		number;
	static int		sum;
	int		i;
	int		fd1;
	fd1 = open("inventory.txt", O_RDONLY);
	i = 1;
	number = 0;
	sum = 0;
	while (i <= 100)
	{
		line = get_next_line(fd1);
		line_1 = get_next_line(fd1);
		line_2 = get_next_line(fd1);
		number = ft_strcmp_three(line, line_1, line_2);
		number = ft_correctnum(number);
		sum = sum + number;
		i++;
	}
	printf("%d\n", sum);
}
