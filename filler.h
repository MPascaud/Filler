/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/01 14:09:45 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 16:17:59 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define FILLER_H

# define BUFF_SIZE 300
# define MAX_FD 4865
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int				get_next_line(const int fd, char **line);
char			*ft_strstr(const char *haystack, const char *needle);
size_t			ft_strlen(const char *s);
char			*ft_strncat(char *dest, const char *src, size_t n);
char			*ft_strnew(size_t size);
char			*ft_strcpy(char *dest, const char *src);
typedef struct	s_data
{
	int			me;
	int			opp;
	int			*board;
	char		**war;
	int			*piece;
	char		**shapiece;
}				t_data;
typedef struct	s_heater
{
	int			heat;
	int			i;
	int			j;
}				t_heater;
typedef struct	s_move
{
	int			hori;
	int			verti;
}				t_move;
typedef struct	s_v
{
	char		*tmp;
	t_data		*data;
	int			war;
	int			shapiece;
	int			what;
}				t_v;
typedef struct	s_v2
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			possible;
	int			what;
	int			midwhat;
}				t_v2;
typedef struct	s_v0
{
	int			heat;
	int			middle;
	int			i;
	int			j;
	int			heat2;
	int			okleft;
	int			okright;
	int			okup;
	int			okdown;
}				t_v0;
typedef struct	s_vh
{
	int			i;
	int			j;
	int			k;
	int			l;
	int			possible;
	int			thermometer;
	t_heater	*heater;
	int			what;
	int			midwhat;
}				t_vh;
typedef struct	s_v1
{
	int			line;
	int			i;
	int			change;
	int			heat;
}				t_v1;
void			ft_free(t_data **data, int *war, int *shapiece);
void			ft_initialization(t_v *v);
void			ft_initialization2(t_v2 *v2);
void			ft_free2(t_v *v);
int				ft_possible(t_data *data);
void			ft_heatmap(t_data *data);
void			ft_initialization_heatmap(t_v1 *v1, t_data *data);
void			ft_assignment(t_v1 *v1, t_data *data);
int				ft_distance(t_data *data);
void			ft_heatmap2(t_data *data);
void			ft_heatmap_01p2(t_data *data);
void			ft_heatmap_00p2(t_data *data);
void			ft_okright_00p2(int *okright, t_data *data);
void			ft_okup_00p2(int *okup, t_data *data);
void			ft_down_00p2(int *okdown, t_data *data);
void			ft_okleft_00p2(int *okleft, t_data *data);
void			ft_init00(t_v0 *v0, t_data *data);
void			ft_init01(t_v0 *v0, t_data *data);
void			ft_okright_01p2(int *okright, t_data *data);
void			ft_okup_01p2(int *okup, t_data *data);
void			ft_down_01p2(int *okdown, t_data *data);
void			ft_okleft_01p2(int *okleft, t_data *data);
int				ft_2nchance(t_data *data);
int				ft_2ndplace(t_data *data, t_move *move);
void			ft_board(t_data *data, char *tmp);
void			ft_piece(t_data *data, char *tmp);
void			ft_war(t_data *data, char *tmp, int war);
void			ft_shapiece(t_data *data, char *tmp, int shapiece);
void			ft_afficher_variables(t_data *data,
		char *tmp, int war, int shapiece);
void			ft_putchar(char c);
void			ft_putnbr(int nb);
int				ft_possible_heat(t_data *data);
void			ft_initialization_heat(t_vh *vh);
int				ft_midground_heater(t_vh *vh, t_data *data);
int				ft_background_heater(t_vh *vh, t_data *data);
int				ft_test(t_data *data);
void			ft_place_heat(t_data *data);
void			ft_hot(t_data *data);
void			ft_heatmap_01p2(t_data *data);
int				ft_2ndchance(t_data *data);

#endif
