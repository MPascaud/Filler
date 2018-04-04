/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:32:28 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 22:57:07 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_background_heater_write(t_vh *vh)
{
	ft_putnbr(vh->heater->i);
	write(1, " ", 1);
	ft_putnbr(vh->heater->j);
	write(1, "\n", 1);
}

void	ft_background_heater2(t_vh *vh, t_data *data)
{
	if (data->war[vh->k + vh->i][vh->l + vh->j] == data->me)
		(vh->possible)++;
	if (data->war[vh->k + vh->i][vh->l + vh->j] == data->opp)
		vh->possible = 2;
	if (vh->thermometer < data->war[vh->k + vh->i][vh->l + vh->j]
			&& data->war[vh->k + vh->i][vh->l + vh->j] != data->me
			&& data->war[vh->k + vh->i][vh->l + vh->j] != data->opp)
		vh->thermometer = data->war[vh->k + vh->i][vh->l + vh->j];
}

int		ft_background_heater(t_vh *vh, t_data *data)
{
	if (data->shapiece[vh->k][vh->l] == '*')
	{
		if ((vh->k + vh->i) > (data->board[0] - 1)
				|| (vh->l + vh->j) > (data->board[1] - 1))
		{
			vh->possible = 2;
			if (vh->j == 0)
			{
				ft_background_heater_write(vh);
				if (vh->heater->heat > 0)
				{
					free(vh->heater);
					free(vh);
					return (1);
				}
				free(vh->heater);
				free(vh);
				return (0);
			}
			return (2);
		}
		ft_background_heater2(vh, data);
	}
	(vh->l)++;
	return (4);
}

int		ft_possible_heat(t_data *data)
{
	t_vh	*vh;

	vh = (t_vh*)malloc(sizeof(t_vh));
	ft_initialization_heat(vh);
	while (vh->i < data->board[0])
	{
		vh->midwhat = ft_midground_heater(vh, data);
		if (vh->midwhat == 0)
			return (0);
		if (vh->midwhat == 1)
			return (1);
	}
	ft_putnbr(vh->heater->i);
	write(1, " ", 1);
	ft_putnbr(vh->heater->j);
	write(1, "\n", 1);
	if (vh->heater->heat > 0)
	{
		free(vh->heater);
		free(vh);
		return (1);
	}
	free(vh->heater);
	free(vh);
	return (0);
}

void	ft_place_heat(t_data *data)
{
	ft_possible_heat(data);
}
