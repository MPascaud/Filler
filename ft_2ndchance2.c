/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 15:40:35 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			ft_2ndplace_ground(t_v2 *v2, t_data *data)
{
	while (data->shapiece[v2->k][v2->l])
	{
		if (data->shapiece[v2->k][v2->l] == '*')
		{
			if ((v2->k + v2->i) > (data->board[0] - 1)
					|| (v2->l + v2->j) > (data->board[1] - 1))
			{
				v2->possible = 2;
				if (v2->j == 0)
				{
					free(v2);
					return (0);
				}
			}
			if (data->war[v2->k + v2->i][v2->l + v2->j] == data->me)
				(v2->possible)++;
			if (data->war[v2->k + v2->i][v2->l + v2->j] == data->opp)
				v2->possible = 2;
		}
		(v2->l)++;
	}
	v2->l = 0;
	(v2->k)++;
	return (1);
}

int			ft_2ndplace_top(t_v2 *v2, t_data *data, t_move *move)
{
	while (data->war[v2->i][v2->j])
	{
		while (data->shapiece[v2->k] != NULL)
		{
			v2->what = ft_2ndplace_ground(v2, data);
			if (v2->what == 0)
				return (0);
		}
		if (v2->possible == 1)
		{
			ft_putnbr(v2->i - move->verti);
			write(1, " ", 1);
			ft_putnbr(v2->j - move->hori);
			write(1, "\n", 1);
			free(v2);
			return (1);
		}
		v2->possible = 0;
		v2->k = 0;
		(v2->j)++;
	}
	v2->j = 0;
	(v2->i)++;
	return (2);
}

int			ft_2ndplace(t_data *data, t_move *move)
{
	t_v2	*v2;

	v2 = (t_v2*)malloc(sizeof(t_v2));
	v2->i = 0;
	v2->j = 0;
	v2->k = 0;
	v2->l = 0;
	v2->possible = 0;
	v2->what = 0;
	v2->midwhat = 0;
	while (data->war[v2->i] != NULL)
	{
		v2->midwhat = ft_2ndplace_top(v2, data, move);
		if (v2->midwhat == 0)
			return (0);
		if (v2->midwhat == 1)
			return (1);
	}
	free(v2);
	return (0);
}
