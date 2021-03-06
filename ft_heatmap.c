/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 14:13:43 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_heatmap_ground1(t_v1 *v1, t_data *data)
{
	v1->change = v1->i;
	while (v1->change >= 0 && v1->heat >= 0)
	{
		if (data->war[v1->line][v1->change] != data->me
				&& data->war[v1->line][v1->change] != data->opp
				&& data->war[v1->line][v1->change] < v1->heat)
		{
			data->war[v1->line][v1->change] = v1->heat;
		}
		(v1->heat)--;
		(v1->change)--;
	}
	v1->change = v1->i;
	v1->heat = ft_distance(data);
	while (v1->change < data->board[1] && v1->heat >= 0)
	{
		if (data->war[v1->line][v1->change] != data->me
				&& data->war[v1->line][v1->change] != data->opp
				&& data->war[v1->line][v1->change] < v1->heat)
		{
			data->war[v1->line][v1->change] = v1->heat;
		}
		(v1->heat)--;
		(v1->change)++;
	}
}

void	ft_heatmap_top1(t_v1 *v1, t_data *data)
{
	v1->i = 0;
	v1->line = 0;
	while (v1->line < data->board[0])
	{
		while (v1->i < data->board[1])
		{
			if (data->war[v1->line][v1->i] == data->opp)
				ft_heatmap_ground1(v1, data);
			(v1->i)++;
		}
		v1->i = 0;
		v1->heat = ft_distance(data);
		(v1->line)++;
	}
}

void	ft_heatmap_ground2(t_v1 *v1, t_data *data)
{
	v1->change = v1->line;
	while (v1->change >= 0 && v1->heat >= 0)
	{
		if (data->war[v1->change][v1->i] != data->me
				&& data->war[v1->change][v1->i] != data->opp
				&& data->war[v1->change][v1->i] < v1->heat)
		{
			data->war[v1->change][v1->i] = v1->heat;
		}
		(v1->heat)--;
		(v1->change)--;
	}
	v1->change = v1->line;
	v1->heat = ft_distance(data);
	while (v1->change < data->board[0] && v1->heat >= 0)
	{
		if (data->war[v1->change][v1->i] != data->me
				&& data->war[v1->change][v1->i] != data->opp
				&& data->war[v1->change][v1->i] < v1->heat)
		{
			data->war[v1->change][v1->i] = v1->heat;
		}
		(v1->heat)--;
		(v1->change)++;
	}
}

void	ft_heatmap(t_data *data)
{
	t_v1	*v1;

	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;
	v1 = (t_v1*)malloc(sizeof(t_v1));
	ft_initialization_heatmap(v1, data);
	ft_assignment(v1, data);
	ft_heatmap_top1(v1, data);
	v1->line = 0;
	v1->i = 0;
	v1->heat = ft_distance(data);
	while (v1->line < data->board[0])
	{
		while (v1->i < data->board[1])
		{
			if (data->war[v1->line][v1->i] == data->opp)
				ft_heatmap_ground2(v1, data);
			(v1->i)++;
			v1->heat = ft_distance(data);
		}
		v1->i = 0;
		(v1->line)++;
	}
	free(v1);
}
