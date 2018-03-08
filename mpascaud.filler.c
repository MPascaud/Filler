/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 21:06:56 by mpascaud         ###   ########.fr       */
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

void	ft_piece(t_data *data, char *tmp)
{
	int		nb;
	int		i;

	data->piece = (int*)malloc(sizeof(int) * 2);
	nb = 0;
	i = 6;
	while (tmp[i] != ' ')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->piece[0] = nb;
	nb = 0;
	i++;
	while (tmp[i] != ':')
	{
		nb = (nb * 10) + (tmp[i] - '0');
		i++;
	}
	data->piece[1] = nb;
//	dprintf(FDtest, "%d %d\n", data->piece[0], data->piece[1]);
}

void	ft_war(t_data *data, char *tmp, int war)
{
	int		i;
	int		k;

	i = 4;
	k = 0;
	data->war[war] = (char*)malloc(sizeof(char) * (data->board[1] + 1));
	while (tmp[i])
	{
		data->war[war][k] = tmp[i];
		k++;
		i++;
	}
	data->war[war][k] = '\0';
//	dprintf(FDtest, "coucou%s\n", data->war[war]);

}

void	ft_shapiece(t_data *data, char *tmp, int shapiece)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	data->shapiece[shapiece] = (char*)malloc(sizeof(char) * (data->piece[1] + 1));
	while (tmp[i])
	{
		data->shapiece[shapiece][k] = tmp[i];
		k++;
		i++;
	}
	data->shapiece[shapiece][k] = '\0';
//	dprintf(FDtest, "coucou%s\n", data->shapiece[shapiece]);
}


int		main(void)
{
	char	*tmp;
	t_data	*data;
//	int		board;
	int		war;
//	int		alloc;
	int		shapiece;

//	alloc = 0;
//	board = 0;
	war = 0;
	shapiece = 0;
	data = (t_data*)malloc(sizeof(t_data));
	//data->war = (char**)malloc(sizeof(char*) * 100);
	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_strstr(tmp, "Plateau"))
		{
			ft_board(data, tmp);
		//	dprintf(FDtest, "%s\n", tmp);
		//	dprintf(FDtest, "COUCOU\n");
		}
		//dprintf(FDtest, "%s\n", tmp);
		if (tmp[0] >= 48 && tmp[0] <= 57)
		{
			if (war == 0)
			{
				data->war = (char**)malloc(sizeof(char*) * data->board[0]);
			//	alloc = 1;
			}
			ft_war(data, tmp, war);
			war++;
		}
		if (ft_strstr(tmp, "Piece"))
		{
			ft_piece(data, tmp);
		}
		if (tmp[0] == '.' || tmp[0] == '*')
		{
			if (shapiece == 0)
			{
				data->shapiece = (char**)malloc(sizeof(char*) * data->piece[0]);
			//	piece == 1;
			}
			ft_shapiece(data, tmp, shapiece);
			shapiece++;
			if (shapiece == data->piece[0])
			{
				//ft_filler(data);
				//ft_free(data, war, shapiece);
				dprintf(FDtest, "coucou\n");
			//	break ;
			}
		}

	}
	int i;
	i = 0;
	while (data->war[i])
	{
		dprintf(FDtest, "%s\n", data->war[i]);
		i++;
	}
	return (0);
}
