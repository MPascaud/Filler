/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 18:32:28 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/19 19:40:19 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */




#include "filler.h"


int         ft_test(t_data *data)
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
		while (data->war[i][j] != '\0')
		{
			while (data->shapiece[k] != NULL)
			{
				while (data->shapiece[k][l] != '\0')
				{
					if (data->shapiece[k][l] == '*' /*&& (k + i) < data->board[0] && (l + j) < data->board[1]*/)
					{
						if ((k + i) > (data->board[0] - 1) || (l + j) > (data->board[1] - 1))
						{
						//	dprintf(FDtest, "i = %d, j = %d, k = %d, l = %d\n", i, j, k, l);	
							possible = 2;
							if (j == 0)
							{
								write (1, "0 0\n", 4);
								return (0);
							}
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
			//	dprintf(FDtest, "ligne = %d, case = %d\n", i, j);
				ft_putnbr(i);
				write(1, " ", 1);
				ft_putnbr(j);
				write(1, "\n", 1);
				return (1);
			}
			possible = 0;
			k = 0;
			j++;
		}
		j = 0;
		i++;
	}
	write (1, "0 0\n", 4);
	dprintf(FDtest, "placement impossible");
	return (0);
}


