/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_possible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 16:56:37 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 17:02:15 by mpascaud         ###   ########.fr       */
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
					if (data->shapiece[k][l] == '*' && (k + i) < data->board[0] && (l + j) < data->board[1])
					{
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
				dprintf(FDtest, "ligne = %d, case = %d\n", i, j);
				return (1);
			}
			possible = 0;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	dprintf(FDtest, "placement impossible");
	return (0);
}

