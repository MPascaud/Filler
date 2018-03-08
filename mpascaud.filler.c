/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 17:22:41 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "filler.h"
#define FDtest open("/dev/ttys001", O_RDWR)




void	ft_board(t_data *data, char *tmp)
{
	int		nb;
	int		i;

	data->board = (int*)malloc(sizeof(int) * 2);
	nb = 0;
	i = 8;
	while (tmp[i] != ' ')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->board[0] = nb;
	nb = 0;
	i++;
	while (tmp[i] != ':')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->board[1] = nb;
//	dprintf(FDtest, "%d %d\n", data->board[0], data->board[1]);

}

int		main(int argc, char **argv)
{
	char	*tmp;
	t_data	*data;
	int		board;


	board = 0;
	data = (t_data*)malloc(sizeof(t_data));
	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_strstr(tmp, "Plateau") && board == 0)
		{
			ft_board(data, tmp);
		//	dprintf(FDtest, "%s\n", tmp);
		//	dprintf(FDtest, "COUCOU\n");
		}
		//dprintf(FDtest, "%s\n", tmp);
	}
	return (0);
}
