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
	int 	total;
	int		i = 1;
	int		j = 0;
	int		fd1 = open("day1.txt", O_RDONLY);
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
	total = number[249] + number[248] + number[247];
	printf("%d\n", total);
}
