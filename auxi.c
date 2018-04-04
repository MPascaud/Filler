/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/02 19:00:57 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_free(t_data **data, int *war, int *shapiece)
{
	int		i;

	i = 0;
	(*war) = 0;
	(*shapiece) = 0;
	(*data)->board[1] = 0;
	free((*data)->board);
	while ((*data)->war[i])
	{
		free((*data)->war[i]);
		i++;
	}
	free((*data)->war[i]);
	(*data)->war[0] = NULL;
	free((*data)->war);
	free((*data)->piece);
	i = 0;
	while ((*data)->shapiece[i])
	{
		free((*data)->shapiece[i]);
		i++;
	}
	free((*data)->shapiece[i]);
	(*data)->shapiece[0] = NULL;
	free((*data)->shapiece);
}

void	ft_initialization(t_v *v)
{
	v->war = 0;
	v->shapiece = 0;
	v->data = (t_data*)malloc(sizeof(t_data));
	v->what = 0;
}

void	ft_free2(t_v *v)
{
	free(v->data);
	free(v->tmp);
	free(v);
}
