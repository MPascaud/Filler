/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 16:20:16 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_whoami(char ***tmp, t_data ***data)
{
	if (ft_strstr(*(*tmp), "mpascaud"))
	{
		if ((*(*tmp))[10] == '1')
		{
			(*(*data))->me = 126;
			(*(*data))->opp = 127;
		}
		else
		{
			(*(*data))->me = 127;
			(*(*data))->opp = 126;
		}
	}
}

void	ft_whatzemap(char ***tmp, t_data ***data, int **war)
{
	if ((*(*tmp))[0] >= 48 && (*(*tmp))[0] <= 57)
	{
		if (*(*war) == 0)
			(*(*data))->war = (char**)malloc(sizeof(char*)
					* ((*(*data))->board[0] + 1));
		ft_war(*(*data), *(*tmp), *(*war));
		(*(*war))++;
		if (*(*war) == (*(*data))->board[0])
			(*(*data))->war[*(*war)] = NULL;
	}
}

int		ft_ins(char **tmp, t_data **data, int *war, int *shapiece)
{
	if (*tmp == NULL)
		return (0);
	ft_whoami(&tmp, &data);
	if (ft_strstr((*tmp), "Plateau"))
		ft_board((*data), *tmp);
	ft_whatzemap(&tmp, &data, &war);
	if (ft_strstr(*tmp, "Piece"))
		ft_piece(*data, *tmp);
	if ((*tmp)[0] == '.' || (*tmp)[0] == '*')
	{
		if (*shapiece == 0)
			(*data)->shapiece = (char**)malloc(sizeof(char*)
					* ((*data)->piece[0] + 1));
		ft_shapiece(*data, *tmp, *shapiece);
		(*shapiece)++;
		if (*shapiece == (*data)->piece[0])
		{
			(*data)->shapiece[*shapiece] = NULL;
			return (2);
		}
	}
	return (1);
}

int		ft_outside(int *war, t_data **data, int *shapiece, char **tmp)
{
	if (*war == 0)
		return (2);
	ft_hot(*data);
	if (ft_possible(*data) == 1)
	{
		ft_place_heat(*data);
	}
	if (ft_possible(*data) == 0)
		if (ft_2ndchance(*data) == 0)
		{
			if ((*data)->board[1] == 0)
				return (0);
			ft_free(&(*data), &(*war), &(*shapiece));
			free(*tmp);
			free(*data);
			write(1, "0 0\n", 4);
			return (0);
		}
	ft_free(&(*data), &(*war), &(*shapiece));
	return (1);
}

int		main(void)
{
	t_v		*v;

	v = (t_v*)malloc(sizeof(t_v));
	ft_initialization(v);
	while (1)
	{
		while (get_next_line(0, &(v->tmp)))
		{
			v->what = ft_ins(&(v->tmp), &(v->data), &(v->war), &(v->shapiece));
			if (v->what == 0)
				return (0);
			free(v->tmp);
			v->tmp = NULL;
			if (v->what == 2)
				break ;
		}
		v->what = ft_outside(&(v->war), &(v->data), &(v->shapiece), &(v->tmp));
		if ((v->what) == 0)
			return (0);
		if ((v->what) == 2)
			break ;
	}
	ft_free2(v);
	return (0);
}
