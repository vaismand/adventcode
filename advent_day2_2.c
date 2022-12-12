#include "get_next_line.h"

int    check_conditions(char *line)
{
    char *arr[8];
    char *arr2;
    int number;

    arr[0] = "A X\n";
    arr[1] = "A Y\n";
    arr[2] = "A Z\n";
    arr[3] = "B X\n";
    arr[4] = "B Y\n";
    arr[5] = "B Z\n";
    arr[6] = "C X\n";
    arr[7] = "C Y\n";
    arr[8] = "C Z\n";
    number = 0;
    if (strcmp(line,arr[0]) == 0)
        number = 3;
    else if (strcmp(line,arr[1]) == 0)
        number = 4;
    else if (strcmp(line,arr[2]) == 0)
        number = 8;
    else if (strcmp(line,arr[3]) == 0)
        number = 1;
    else if (strcmp(line,arr[4]) == 0)
        number = 5;
    else if (strcmp(line,arr[5]) == 0)
        number = 9;
    else if (strcmp(line,arr[6]) == 0)
        number = 2;
    else if (strcmp(line,arr[7]) == 0)
        number = 6;
    else if (strcmp(line,arr[8]) == 0)
        number = 7;
    return (number);
}

int    main(void)
{
    char    *line;
    static int        number = 0;
    int        i = 1;
    int        fd1 = open("day2.txt", O_RDONLY);
    while (i <= 2500)
    {
        line = get_next_line(fd1);
        number = number + check_conditions(line);
        i++;
    }
	printf("%d\n", number);
}
