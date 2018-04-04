/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/04 14:14:13 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialization_heatmap(t_v1 *v1, t_data *data)
{
	v1->line = 0;
	v1->i = 0;
	v1->change = 0;
	v1->heat = ft_distance(data);
}

void	ft_assignment(t_v1 *v1, t_data *data)
{
	while (v1->line < data->board[0])
	{
		while (v1->i < data->board[1])
		{
			if (data->war[v1->line][v1->i] == '.')
				data->war[v1->line][v1->i] = '0';
			if (data->war[v1->line][v1->i] == 'O')
				data->war[v1->line][v1->i] = 126;
			if (data->war[v1->line][v1->i] == 'X')
				data->war[v1->line][v1->i] = 127;
			(v1->i)++;
		}
		v1->i = 0;
		(v1->line)++;
	}
}
