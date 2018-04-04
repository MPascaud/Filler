/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 18:24:15 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_okright_01p2(int *okright, t_data *data)
{
	int		line;

	line = 0;
	while (line < data->board[0])
	{
		if (data->war[line][data->board[1] - 1] == data->opp)
		{
			*okright = 1;
		}
		line++;
	}
}

void	ft_okup_01p2(int *okup, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[0][i] == data->opp)
		{
			*okup = 1;
		}
		i++;
	}
}

void	ft_down_01p2(int *okdown, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[data->board[0] - 1][i] == data->me)
			*okdown = 1;
		i++;
	}
}

void	ft_okleft_01p2(int *okleft, t_data *data)
{
	int		line;

	line = 0;
	while (line < data->board[0])
	{
		if (data->war[line][0] == data->me)
			*okleft = 1;
		line++;
	}
}

void	ft_init01(t_v0 *v0, t_data *data)
{
	v0->okleft = 0;
	v0->okright = 0;
	v0->okup = 0;
	v0->okdown = 0;
	ft_okright_01p2(&(v0->okright), data);
	ft_okup_01p2(&(v0->okup), data);
	ft_down_01p2(&(v0->okdown), data);
	ft_okleft_01p2(&(v0->okleft), data);
	v0->middle = 16;
	v0->heat = (data->board[0] / 1) + 8;
	v0->i = 0;
	v0->j = 0;
}
