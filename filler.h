/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:09:45 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 19:20:17 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# define BUFF_SIZE 15
# define MAX_FD 4865

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>

int		get_next_line(const int fd, char **line);
size_t      ft_strlen(const char *s);
char    *ft_strncat(char *dest, const char *src, size_t n);
char    *ft_strnew(size_t size);
char    *ft_strcpy(char *dest, const char *src);
int     get_next_line(const int fd, char **line);
char    *ft_strstr(const char *haystack, const char *needle);

typedef struct	s_data
{
	int		*board;
	char	**war;
	int		*piece;
	char	**shapiece;
}				t_data;


#endif
