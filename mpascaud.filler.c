/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/19 19:49:57 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "filler.h"
//#define FDtest open("/dev/ttys000", O_RDWR)









/*void	ft_board(t_data *data, char *tmp)
{
	int		nb;
	int		i;

	data->board = (int*)malloc(sizeof(int) * 3);
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
	data->board[2] = '\0';
}*/

/*void	ft_piece(t_data *data, char *tmp)
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
	data->piece[2] = '\0';
}*/

/*void	ft_war(t_data *data, char *tmp, int war)
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
}*/

/*void	ft_shapiece(t_data *data, char *tmp, int shapiece)
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
}
*/


/*void	ft_afficher_variables(t_data *data, char *tmp, int war, int shapiece)
{
	int		i;

	dprintf(FDtest, "me = %c\n", data->me);
	dprintf(FDtest, "opp = %c\n", data->opp);
	dprintf(FDtest, "tmp = %s\n", tmp);
	dprintf(FDtest, "war = %d\n", war);
	dprintf(FDtest, "shapiece = %d\n", shapiece);
	i = 0;
	while (data->board[i])
	{
		dprintf(FDtest, "data->board[%d] = %d\n", i, data->board[i]);
		i++;
	}
	dprintf(FDtest, "data->board[%d] = %d\n", i, data->board[i]);
	i = 0;
	while (data->war[i] != NULL)
	{
		dprintf(FDtest, "data->war[%d] = %s\n", i, data->war[i]);
		i++;
	}
	dprintf(FDtest, "data->war[%d] = %s\n", i, data->war[i]);
	i = 0;
	while (data->piece[i])
	{
		dprintf(FDtest, "data->piece[%d] = %d\n", i, data->piece[i]);
		i++;
	}
	dprintf(FDtest, "data->piece[%d] = %d\n", i, data->piece[i]);
	i = 0;
	while (data->shapiece[i] != NULL)
	{
		dprintf(FDtest, "data->shapiece[%d] = %s\n", i, data->shapiece[i]);
		i++;
	}
	dprintf(FDtest, "data->shapiece[%d] = %s\n", i, data->shapiece[i]);
	
	dprintf(FDtest, "----------------------------------------------------------------------\n");

}*/


/*void	ft_heatmap(t_data *data)
{
	int		line;
	int		i;
	int		change;
	int		heat;

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
*/
/*void	ft_heatmap2(t_data *data)
{
	int		line;
	int		i;
	int		change;
	int		heat;

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
}*/

/*void	ft_putchar(char c)
{
	write(1, &c, 1);
}*/

/*void    ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		if (nb == -2147483648)
		{
			ft_putchar('2');
			nb = -147483648;
		}
	nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar((nb % 10) + '0');
}*/


/*int			ft_possible(t_data *data)
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		possible;

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	possible = 0;
	while (data->war[i] != NULL)
	{
	//	dprintf(FDtest, "data->war[%d] = %s\n", i, data->war[i]);
		while (data->war[i][j])
		{
			//dprintf(FDtest, "data->war[%d][%d] = %c\n", i, j, data->war[i][j]);
			while (data->shapiece[k] != NULL)
			{
	//			dprintf(FDtest, "data->shapiece[%d] = %s\n", k, data->shapiece[k]);
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
						//dprintf(FDtest, "coucou\n");
					}
					l++;
				}
				l = 0;
				k++;
			}
			if (possible == 1)
			{
				ft_putnbr(i);
				write(1, " ", 1);
				ft_putnbr(j);
				write(1, "\n", 1);
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
//	write(1, "0 0\n", 4);
	return (0);
}*/

void	ft_free(t_data **data, int *war, int *shapiece)
{
	int		i;

	i = 0;
	(*war) = 0;
	(*shapiece) = 0;
	free((*data)->board);
	while ((*data)->war[i])
	{
		free((*data)->war[i]);
		i++;
	}
	free((*data)->war[i]);
	free((*data)->war);
	free((*data)->piece);
	i = 0;
	while ((*data)->shapiece[i])
	{
		free((*data)->shapiece[i]);
		i++;
	}
	free((*data)->shapiece[i]);
	free((*data)->shapiece);
}

int		main(void)
{
	char	*tmp;
	t_data	*data;
	int		war;
	int		shapiece;
	int		impossible;

	war = 0;
	shapiece = 0;
	impossible = 0;
	data = (t_data*)malloc(sizeof(t_data));
	while (1)
	{
		while (get_next_line(0, &tmp))
		{
		//	/*if (tmp[0] == '=' ||*/ tmp == NULL/*ajout anti leaks et seg*/)//si on ne peut plus poser
		//	{
				//write (1, "0 0\n", 4);
				//free data
				//break ;
		//		return (0);
		//	}
		//	if (tmp[0] == '\0')
		//		return(0);
			if (ft_strstr(tmp, "mpascaud"))
			{
				if (tmp[10] == '1')
				{
					data->me = 'O';
					data->opp = 'X';
				}
				else
				{
					data->me = 'X';
					data->opp = 'O';
				}
			}
			if (ft_strstr(tmp, "Plateau"))
			{
				ft_board(data, tmp);
			}
			if (tmp[0] >= 48 && tmp[0] <= 57)
			{
				if (war == 0)
				{
					data->war = (char**)malloc(sizeof(char*) * (data->board[0] + 1));
				}
				ft_war(data, tmp, war);
				war++;
				if (war == data->board[0] || tmp == NULL/*rajout segfault*/)
				{
					data->war[war] = (char*)malloc(sizeof(char));
					data->war[war] = NULL;
				}
			}
			if (ft_strstr(tmp, "Piece"))
			{
				ft_piece(data, tmp);
			}
			if (tmp[0] == '.' || tmp[0] == '*')
			{
				if (shapiece == 0)
				{
					data->shapiece = (char**)malloc(sizeof(char*) * (data->piece[0] + 1));
				}
				ft_shapiece(data, tmp, shapiece);
				shapiece++;
				if (shapiece == data->piece[0] /*|| tmp == NULL*//*2e rajout segfault*/)
				{
					data->shapiece[shapiece] = (char*)malloc(sizeof(char));
					data->shapiece[shapiece] = NULL;
					//	write(1, "0 0\n", 4);
					//write(1, "8 2\n", 4);
					//	write(1, "12 14\n", 6);
			//		free(tmp);
			//		tmp = NULL;
					break ;
				}
			}
			//if (ft_possible(data) == 0)
			//	break ;
		//	if (impossible == 1)
		//		break ;
			free(tmp);
			tmp = NULL;
		}
		ft_heatmap(data);
		ft_heatmap2(data);
		ft_afficher_variables(data, tmp, war, shapiece);
	//	ft_possible(data);
	/*	if (ft_possible(data) == 0)
		{
		//	write(FDtest, "pad place\n", 10);
		//	write(1, "0 0\n", 4);
		//	impossible = 1;
			//break ;
			return (0);
		}*/
		if (ft_possible(data) == 0)
		{
			write(FDtest, "placement impossible\n", 21);
			write (1, "0 0\n", 4);
			return (0);
		}
		if (ft_test(data) == 0)
			return (0);
	//	sleep(1);
//		if (tmp[0] == '=')
//			break ;
	//	if (tmp == NULL || tmp[0] == '\0')
	//		break ;
	//	if (tmp != NULL)
	//	{
		//	free(tmp);
		//	tmp = NULL;
	//	}
		if (tmp == NULL)
			break ;
		if (impossible == 1)
		{
			//write(1, "0 0\n", 4);
			ft_free(&data, &war, &shapiece);
			break ;
		}
		ft_free(&data, &war, &shapiece);
	}
	return (0);
}
