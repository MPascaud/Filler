/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 21:37:15 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_background_test(t_v2 *v2, t_data *data)
{
	if (data->shapiece[v2->k][v2->l] == '*')
	{
		if ((v2->k + v2->i) > (data->board[0] - 1)
				|| (v2->l + v2->j) > (data->board[1] - 1))
		{
			v2->possible = 2;
			if (v2->j == 0)
				return (0);
		}
		if (data->war[v2->k + v2->i][v2->l + v2->j] == data->me)
		{
			(v2->possible)++;
		}
		if (data->war[v2->k + v2->i][v2->l + v2->j] == data->opp)
		{
			v2->possible = 2;
		}
	}
	return (1);
}

int		ft_midground_test(t_v2 *v2, t_data *data)
{
	while (data->shapiece[v2->k] != NULL)
	{
		while (data->shapiece[v2->k][v2->l])
		{
			v2->what = ft_background_test(v2, data);
			if (v2->what == 0)
				return (0);
			(v2->l)++;
		}
		v2->l = 0;
		(v2->k)++;
	}
	if (v2->possible == 1)
	{
		free(v2);
		return (2);
	}
	v2->possible = 0;
	v2->k = 0;
	(v2->j)++;
	return (1);
}

int		ft_possible(t_data *data)
{
	t_v2	*v2;

	v2 = (t_v2*)malloc(sizeof(t_v2));
	ft_initialization2(v2);
	if (data->board[1] == 0)
		return (0);
	while (data->war[v2->i] != NULL)
	{
		while (data->war[v2->i][v2->j])
		{
			v2->midwhat = ft_midground_test(v2, data);
			if (v2->midwhat == 0)
			{
				free(v2);
				return (0);
			}
			if (v2->midwhat == 2)
				return (1);
		}
		v2->j = 0;
		(v2->i)++;
	}
	free(v2);
	return (0);
}
