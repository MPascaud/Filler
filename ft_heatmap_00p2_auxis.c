/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 16:26:23 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_okright_00p2(int *okright, t_data *data)
{
	int		line;

	line = 0;
	while (line < data->board[0])
	{
		if (data->war[line][data->board[1] - 1] == data->me)
		{
			*okright = 1;
		}
		line++;
	}
}

void	ft_okup_00p2(int *okup, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[0][i] == data->me)
		{
			*okup = 1;
		}
		i++;
	}
}

void	ft_down_00p2(int *okdown, t_data *data)
{
	int		i;

	i = 0;
	while (i < data->board[1])
	{
		if (data->war[data->board[0] - 1][i] == data->opp)
			*okdown = 1;
		i++;
	}
}

void	ft_okleft_00p2(int *okleft, t_data *data)
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

void	ft_init00(t_v0 *v0, t_data *data)
{
	v0->okleft = 0;
	v0->okright = 0;
	v0->okup = 0;
	v0->okdown = 0;
	ft_okright_00p2(&(v0->okright), data);
	ft_okup_00p2(&(v0->okup), data);
	ft_down_00p2(&(v0->okdown), data);
	ft_okleft_00p2(&(v0->okleft), data);
	v0->middle = 7;
	v0->heat = (data->board[0] / 1);
	v0->i = 0;
	v0->j = 0;
}
