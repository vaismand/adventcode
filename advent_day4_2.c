#include "get_next_line.h"

int	check_range(char *str, char *str_1, char *str2, char *str_2)
{
	int	s1;
	int	s2;
	int	s3;
	int	s4;

	s1 = ft_atoi(str);
	s2 = ft_atoi(str_1);
	s3 = ft_atoi(str2);
	s4 = ft_atoi(str_2);
	if (s1 >= s3 && s2 <= s4)
		return (1);
	else if (s3 <= s1 && s4 >= s2)
		return (1);
	else if (s1 <= s3 && s2 >= s4)
		return (1);
	else if (s1 >= s3 && s2 <= s4)
		return (1);
	else if (s2 >= s3)
		return (1);
	else
		return (0);
}


int	main(void)
{
	char	*line;
	char	**arr;
	char	**arr2;
	char	**tmp;
	char	*str;
	char	*str_1;
	char	*str2;
	char	*str_2;
	int		result;
	int		i;
	int		fd1;
	fd1 = open("sorting.txt", O_RDONLY);
	i = 1;
	while (i <= 10)
	{
		line = get_next_line(fd1);
		tmp = ft_split(line, ',');
		str = ft_strjoin(tmp[0], "");
		str2 = ft_strjoin(tmp[1], "");
		arr = ft_split(str, '-');
		arr2 = ft_split(str2, '-');
		str = ft_strjoin(arr[0], "");
		str_1 = ft_strjoin(arr[1], "");
		str2 = ft_strjoin(arr2[0], "");
		str_2 = ft_strjoin(arr2[1], "");
		result = check_range(str, str_1, str2, str_2);
		printf("%d\n", result);
		i++;
	}
	printf("%d\n", result);
}
