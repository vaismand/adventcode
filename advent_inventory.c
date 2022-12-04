#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

bool	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n'
	|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_atoi(const char *str)
{
	size_t			i;
	int				sign;
	unsigned int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (ft_isdigit(str[i]))
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (result > 2147483647 && sign == 1)
		return (-1);
	if (result > 2147483648 && sign == -1)
		return (0);
	return (result * sign);
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *left_str, char *buff)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!left_str)
	{
		left_str = (char *)malloc(1 * sizeof(char));
		left_str[0] = '\0';
	}
	if (!left_str || !buff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(left_str) + ft_strlen(buff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (left_str)
		while (left_str[++i] != '\0')
			str[i] = left_str[i];
	while (buff[j] != '\0')
		str[i++] = buff[j++];
	str[ft_strlen(left_str) + ft_strlen(buff)] = '\0';
	free(left_str);
	return (str);
}

char	*ft_get_line(char *left_str)
{
	int		i;
	char	*str;

	i = 0;
	if (!left_str[i])
		return (NULL);
	while (left_str[i] && left_str[i] != '\n')
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (left_str[i] && left_str[i] != '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	if (left_str[i] == '\n')
	{
		str[i] = left_str[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_new_left_str(char *left_str)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (left_str[i] && left_str[i] != '\n')
		i++;
	if (!left_str[i])
	{
		free(left_str);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(left_str) - i + 1));
	if (!str)
		return (NULL);
	i++;
	j = 0;
	while (left_str[i])
		str[j++] = left_str[i++];
	str[j] = '\0';
	free(left_str);
	return (str);
}

char	*ft_read_to_left_str(int fd, char *left_str)
{
	char	*buff;
	int		rd_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
	{
		free(buff);
		return (NULL);
	}
	rd_bytes = 1;
	while (!ft_strchr(left_str, '\n') && rd_bytes != 0)
	{
		rd_bytes = read(fd, buff, BUFFER_SIZE);
		if (rd_bytes == -1)
		{
			free(left_str);
			left_str = NULL;
			free(buff);
			return (NULL);
		}
		buff[rd_bytes] = '\0';
		left_str = ft_strjoin(left_str, buff);
	}
	free(buff);
	return (left_str);
}

char	*get_next_line(int fd)
{
	static char	*left_str;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	left_str = ft_read_to_left_str(fd, left_str);
	if (!left_str)
		return (NULL);
	line = ft_get_line(left_str);
	left_str = ft_new_left_str(left_str);
	return (line);
}

char	*ft_strncpy(char *src)
{
	char	*dest;
	int    i;
	int	   j;
	int	   k;

    i = 0;
	k = 0;
	j = (ft_strlen(src) - 1) / 2;
	dest = (char *)malloc(sizeof(char) * j + 1);
    while (i < j)
    {
        dest[k] = src[i];
		i++;
		k++;
    }
	dest[k] = '\0';
    return (dest);
}

char	*ft_strrncpy(char *src)
{
	char   *dest;
	int    i;
	int	   j;

    i = ft_strlen(src) - 1;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
    while (i > ft_strlen(src) / 2)
    {
        dest[j++] = src[--i];
    }
	dest[j] = '\0';
    return (dest);
}

int ft_strcmp(char *s1, char *s2, char *s3)
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
		number = ft_strcmp(line, line_1, line_2);
		number = ft_correctnum(number);
		printf("%d\n", number);
		sum = sum + number;
		i++;
	}
	printf("%d\n", sum);
}
