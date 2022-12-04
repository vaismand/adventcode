#include "get_next_line.h"

int	check_conditions(char *line)
{
	char *comb;

	comb = line;

	if (comb == "A X\n")
		return (4);
	else if (comb == "A Y\n")
		return (9);
	else if (comb == "A Z\n")
		return (2);
	else if (comb == "B X\n")
		return (3);
	else if (comb == "B Y\n")
		return (5);
	else if (comb == "B Z\n")
		return (7);
	else if (comb == "C X\n")
		return (8);
	else if (comb == "C Y\n")
		return (1);
	else if (comb == "C Z\0")
		return (6);
	else
		return (0);
}

int	main(void)
{
	char	*line;
	static int		number;
	int		i;
	int		fd1;
	fd1 = open("game.txt", O_RDONLY);
	i = 1;
	number = 0;
	while (i <= 10)
	{
		line = get_next_line(fd1);
		printf("%s", line);
		number = number + check_conditions(line);
		printf("%d\n", number);
		i++;
	}
}
