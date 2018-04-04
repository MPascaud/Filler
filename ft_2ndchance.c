/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 15:03:26 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		ft_2nd_distance(t_move *move, int *i, int *j, t_data *data)
{
	while (*i < data->piece[0])
	{
		while (data->shapiece[*i][*j])
		{
			if (data->shapiece[*i][*j] == '*' && *j <= move->hori)
			{
				move->hori = *j;
			}
			if (data->shapiece[*i][*j] == '*' && *i <= move->verti)
			{
				move->verti = *i;
			}
			(*j)++;
		}
		(*i)++;
		*j = 0;
	}
}

int			ft_2ndchance2nd(t_move *move, int *i, int *j, t_data *data)
{
	*i = 0;
	*j = 0;
	while ((*i + move->verti) < data->piece[0])
	{
		while (data->shapiece[*i + move->verti][*j + move->hori])
		{
			data->shapiece[*i][*j] =
				data->shapiece[*i + move->verti][*j + move->hori];
			(*j)++;
		}
		while (data->shapiece[*i][*j])
		{
			data->shapiece[*i][*j] = '.';
			(*j)++;
		}
		(*i)++;
		*j = 0;
	}
	if (ft_possible(data) == 1)
	{
		ft_2ndplace(data, move);
		free(move);
		return (1);
	}
	return (0);
}

int			ft_2ndchance(t_data *data)
{
	t_move		*move;
	int			i;
	int			j;
	int			what;

	move = (t_move*)malloc(sizeof(t_move));
	move->hori = data->piece[1] - 1;
	move->verti = data->piece[0] - 1;
	i = 0;
	j = 0;
	what = 0;
	if (data->board[1] == 0)
	{
		free(move);
		return (0);
	}
	ft_2nd_distance(move, &i, &j, data);
	what = ft_2ndchance2nd(move, &i, &j, data);
	if (what == 1)
		return (1);
	free(move);
	return (0);
}
