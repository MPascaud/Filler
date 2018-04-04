/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:32:28 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 22:57:55 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialization_heat(t_vh *vh)
{
	vh->i = 0;
	vh->j = 0;
	vh->k = 0;
	vh->l = 0;
	vh->possible = 0;
	vh->thermometer = 0;
	vh->heater = (t_heater*)malloc(sizeof(t_heater));
	vh->what = 0;
	vh->midwhat = 0;
	vh->heater->heat = 0;
	vh->heater->i = 0;
	vh->heater->j = 0;
}

void	ft_midground_heater_reinit(t_vh *vh)
{
	vh->possible = 0;
	vh->k = 0;
	vh->thermometer = 0;
	(vh->j)++;
}

void	ft_midground_heater_mesure(t_vh *vh)
{
	vh->heater->heat = vh->thermometer;
	vh->heater->i = vh->i;
	vh->heater->j = vh->j;
}

int		ft_midground_heater(t_vh *vh, t_data *data)
{
	while (vh->j < data->board[1])
	{
		while (vh->k < data->piece[0])
		{
			while (vh->l < data->piece[1])
			{
				vh->what = ft_background_heater(vh, data);
				if (vh->what == 0)
					return (0);
				if (vh->what == 1)
					return (1);
				if (vh->what == 2)
					break ;
			}
			vh->l = 0;
			(vh->k)++;
		}
		if (vh->possible == 1)
			if (vh->thermometer > vh->heater->heat)
				ft_midground_heater_mesure(vh);
		ft_midground_heater_reinit(vh);
	}
	vh->j = 0;
	(vh->i)++;
	return (3);
}
