/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:32:28 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 18:31:57 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_initialization2(t_v2 *v2)
{
	v2->i = 0;
	v2->j = 0;
	v2->k = 0;
	v2->l = 0;
	v2->possible = 0;
	v2->what = 0;
	v2->midwhat = 0;
}

int		ft_background(t_v2 *v2, t_data *data)
{
	if (data->shapiece[v2->k][v2->l] == '*')
	{
		if ((v2->k + v2->i) > (data->board[0] - 1)
				|| (v2->l + v2->j) > (data->board[1] - 1))
		{
			v2->possible = 2;
			if (v2->j == 0)
			{
				write(1, "0 0\n", 4);
				return (0);
			}
			return (2);
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
	(v2->l)++;
	return (1);
}

int		ft_midground(t_v2 *v2, t_data *data)
{
	while (v2->k < data->piece[0])
	{
		while (v2->l < data->piece[1])
		{
			v2->what = ft_background(v2, data);
			if (v2->what == 0)
				return (0);
			if (v2->what == 2)
				return (2);
		}
		v2->l = 0;
		(v2->k)++;
	}
	if (v2->possible == 1)
	{
		ft_putnbr(v2->i);
		write(1, " ", 1);
		ft_putnbr(v2->j);
		write(1, "\n", 1);
		return (1);
	}
	v2->possible = 0;
	v2->k = 0;
	(v2->j)++;
	return (1);
}

int		ft_test(t_data *data)
{
	t_v2	*v2;

	v2 = (t_v2*)malloc(sizeof(t_v2));
	ft_initialization2(v2);
	while (v2->i < data->board[0])
	{
		while (v2->j < data->board[1])
		{
			v2->midwhat = ft_midground(v2, data);
			if (v2->midwhat == 0)
				return (0);
			if (v2->midwhat == 1)
				return (1);
			if (v2->midwhat == 2)
				break ;
		}
		v2->j = 0;
		(v2->i)++;
	}
	free(v2);
	write(1, "0 0\n", 4);
	return (0);
}
