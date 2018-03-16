/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heatmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 17:07:35 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/16 17:12:37 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"


void    ft_heatmap(t_data *data)
{
	int     line;
	int     i;
	int     change;
	int     heat;

	line = 0;
	i = 0;
	change = 0;
	heat = 9;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
		{
			if (data->war[line][i] == '.')
				data->war[line][i] = '0';
			i++;
		}
		i = 0;
		line++;
	}
	i = 0;
	line = 0;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
		{
			if (data->war[line][i] == data->opp)
			{
				change = i;
				while (change >= 0 && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat + '0')
					{
						data->war[line][change] = heat + '0';
					}
					heat--;
					change--;
				}
				change = i;
				heat = 9;
				while (data->war[line][change] && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat + '0')
					{
						data->war[line][change] = heat + '0';
					}
					heat--;
					change++;
				}
			}
			i++;
		}
		i = 0;
		heat = 9;
		line++;
	}
	line = 0;
	i = 0;
	heat = 9;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
		{
			if (data->war[line][i] == data->opp)
			{
				change = line;
				while (change >= 0 && heat >= 0)
				{
					if (data->war[change][i] != data->me && data->war[change][i] != data->opp
							&& data->war[change][i] < heat + '0')
					{
						data->war[change][i] = heat + '0';
					}
					heat--;
					change--;
				}
				change = line;
				heat = 9;
				while (change < data->board[0] && heat >= 0)
				{
					if (data->war[change][i] != data->me && data->war[change][i] != data->opp
							&& data->war[change][i] < heat + '0')
					{
						data->war[change][i] = heat + '0';
					}
					heat--;
					change++;
				}
			}
			i++;
			heat = 9;
		}
		i = 0;
		line++;
	}
}

void    ft_heatmap2(t_data *data)
{
	int     line;
	int     i;
	int     change;
	int     heat;

	line = 0;
	i = 0;
	change = 0;
	heat = 9;
	while (data->war[line] != NULL)
	{
		while (data->war[line][i])
		{
			if (data->war[line][i] > '1' && data->war[line][i] <= '9')
			{
				change = i;
				heat = data->war[line][i] - '0';
				while (change >= 0 && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat + '0')
					{
						data->war[line][change] = heat + '0';
					}
					heat--;
					change--;
				}
				change = i;
				heat = data->war[line][i] - '0';
				while (data->war[line][change] && heat >= 0)
				{
					if (data->war[line][change] != data->me && data->war[line][change] != data->opp
							&& data->war[line][change] < heat + '0')
					{
						data->war[line][change] = heat + '0';
					}
					heat--;
					change++;
				}
			}
			i++;
		}
		i = 0;
		line++;
	}
}








