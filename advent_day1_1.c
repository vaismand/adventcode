#include "get_next_line.h"

void	ft_bubblesort(int *arr)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < 5)
	{
		j = 0;
		while (j < 249)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	main(void)
{
	char	*line;
	static int number[250];
	int		i;
	int		j;
	int		fd1;
	fd1 = open("calories.txt", O_RDONLY);
	i = 1;
	j = 0;
	while (i <= 250)
	{
		number[j] = 0;
		line = get_next_line(fd1);
		while (ft_atoi(line) != 0)
		{
			number[j] += ft_atoi(line);
			line = get_next_line(fd1);
		}
		i++;
		j++;
	}
	ft_bubblesort(number);
	printf("%d\n", number[249]);
}
