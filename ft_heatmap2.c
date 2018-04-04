/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 16:08:28 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_heatmap2bis(t_v1 *v1, t_data *data)
{
	v1->change = v1->i;
	v1->heat = data->war[v1->line][v1->i];
	while (v1->change >= 0 && v1->heat >= 0)
	{
		if (data->war[v1->line][v1->change] != data->me
				&& data->war[v1->line][v1->change] != data->opp
				&& data->war[v1->line][v1->change] < v1->heat)
			data->war[v1->line][v1->change] = v1->heat;
		(v1->heat)--;
		(v1->change)--;
	}
	v1->change = v1->i;
	v1->heat = data->war[v1->line][v1->i];
	while (v1->change < data->board[1] && v1->heat >= 0)
	{
		if (data->war[v1->line][v1->change] != data->me
				&& data->war[v1->line][v1->change] != data->opp
				&& data->war[v1->line][v1->change] < v1->heat)
			data->war[v1->line][v1->change] = v1->heat;
		(v1->heat)--;
		(v1->change)++;
	}
}

void	ft_heatmap2(t_data *data)
{
	t_v1	*v1;

	if (data->war[0] == NULL || data->shapiece[0] == NULL)
		return ;
	v1 = (t_v1*)malloc(sizeof(t_v1));
	v1->line = 0;
	v1->i = 0;
	v1->change = 0;
	v1->heat = ft_distance(data);
	while (v1->line < data->board[0])
	{
		while (v1->i < data->board[1])
		{
			if (data->war[v1->line][v1->i] > 0
					&& data->war[v1->line][v1->i] <= 120)
				ft_heatmap2bis(v1, data);
			(v1->i)++;
		}
		v1->i = 0;
		(v1->line)++;
	}
	free(v1);
}
