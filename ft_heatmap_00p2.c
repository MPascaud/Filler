/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 23:04:38 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_00left(t_v0 *v0, t_data *data)
{
	while (v0->heat > 0)
	{
		v0->heat2 = v0->heat;
		while (v0->heat2 > 0)
		{
			if (data->war[v0->middle - v0->j][v0->i] != data->me
					&& data->war[v0->middle - v0->j][v0->i] != data->opp)
				if (v0->okleft == 0)
					data->war[v0->middle - v0->j][v0->i] += v0->heat2;
			if (data->war[v0->middle + v0->j + 1][v0->i] != data->me
					&& data->war[v0->middle + v0->j + 1][v0->i] != data->opp)
				if (v0->okleft == 0)
					data->war[v0->middle + v0->j + 1][v0->i] += v0->heat2;
			(v0->j)++;
			v0->heat2 -= 4;
		}
		(v0->i)++;
		v0->heat -= 1;
		v0->j = 0;
	}
}

void	ft_00right(t_v0 *v0, t_data *data)
{
	v0->middle = 13;
	v0->heat = data->board[0] / 2;
	v0->i = data->board[1] - 1;
	while (v0->heat > 0)
	{
		v0->heat2 = v0->heat;
		while (v0->heat2 > 0)
		{
			if (data->war[v0->middle - v0->j][v0->i] != data->me
					&& data->war[v0->middle - v0->j][v0->i] != data->opp)
				if (v0->okup == 0 || v0->okleft == 0)
					data->war[v0->middle - v0->j][v0->i] -= v0->heat2;
			(v0->j)++;
			v0->heat2 -= 3;
		}
		(v0->i)--;
		(v0->heat) -= 1;
		(v0->j) = 0;
	}
}

void	ft_00up(t_v0 *v0, t_data *data)
{
	v0->middle = 16;
	v0->heat = (data->board[1] / 2) + 17;
	v0->i = 0;
	while (v0->heat > 0)
	{
		v0->heat2 = v0->heat;
		while (v0->heat2 > 0)
		{
			if (data->war[v0->i][v0->middle - v0->j] != data->me
					&& data->war[v0->i][v0->middle - v0->j] != data->opp)
				if (v0->okup == 0 && v0->okdown == 0 && v0->okleft == 0)
					data->war[v0->i][v0->middle - v0->j] += v0->heat2;
			(v0->j)++;
			(v0->heat2) -= 3;
		}
		(v0->i)++;
		(v0->heat) -= 2;
		(v0->j) = 0;
	}
}

void	ft_00down(t_v0 *v0, t_data *data)
{
	v0->middle = 8;
	v0->heat = 27;
	v0->i = data->board[0] - 1;
	while (v0->heat > 0)
	{
		v0->heat2 = v0->heat;
		while (v0->heat2 > 0)
		{
			if (data->war[v0->i][v0->middle - v0->j] != data->me
					&& data->war[v0->i][v0->middle - v0->j] != data->opp)
				if (v0->okup == 0)
					data->war[v0->i][v0->middle - v0->j] -= v0->heat2;
			if (data->war[v0->i][v0->middle + v0->j + 1] != data->me
					&& data->war[v0->i][v0->middle + v0->j + 1] != data->opp)
				if (v0->okup == 0)
					data->war[v0->i][v0->middle + v0->j + 1] -= v0->heat2;
			(v0->j)++;
			v0->heat2 -= 6;
		}
		(v0->i)--;
		v0->heat -= 2;
		v0->j = 0;
	}
}

void	ft_heatmap_00p2(t_data *data)
{
	t_v0	*v0;

	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;
	v0 = (t_v0*)malloc(sizeof(t_v0));
	ft_init00(v0, data);
	ft_00left(v0, data);
	ft_00right(v0, data);
	ft_00up(v0, data);
	ft_00down(v0, data);
	free(v0);
}
