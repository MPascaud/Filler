/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/19 21:47:30 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


int         ft_possible(t_data *data)
{
	int     i;
	int     j;
	int     k;
	int     l;
	int     possible;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	possible = 0;
	while (data->war[i] != NULL)
	{
		while (data->war[i][j])
		{
			while (data->shapiece[k] != NULL)
			{
				while (data->shapiece[k][l])
				{
					if (data->shapiece[k][l] == '*')
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
							possible = 2;
							if (j == 0)
								return (0);
						}
						if (data->war[k + i][l + j] == data->me)
						{
							possible++;
						}
						if (data->war[k + i][l + j] == data->opp)
						{
							possible = 2;
						}
					}
					l++;
				}
				l = 0;
				k++;
			}
			if (possible == 1)
			{
				return (1);
			}
			possible = 0;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

