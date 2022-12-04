/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvaisman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:51:59 by dvaisman          #+#    #+#             */
/*   Updated: 2022/12/04 15:59:37 by dvaisman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

int		ft_atoi(const char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strcmp_three(char *s1, char *s2, char *s3);
bool	ft_isdigit(int c);
bool	ft_isspace(int c);
char	*ft_strncpy(char *src);
char	*ft_strrncpy(char *src);
char	*ft_strdup(const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);
char	*ft_read_to_left_str(int fd, char *left_str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *left_str, char *buff);
char	*ft_get_line(char *left_str);
char	*ft_new_left_str(char *left_str);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(char *s);
static int	ft_count_word(char const *s, char c);
static int	ft_size_word(char const *s, char c, int i);


#endif
