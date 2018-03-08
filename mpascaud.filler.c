/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mpascaud.filler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:38:30 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 16:45:55 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */





#include "filler.h"
#define FDtest open("/dev/ttys001", O_RDWR)


int		main(int argc, char **argv)
{
	char	*tmp;

	while (get_next_line(0, &tmp) > 0)
	{
		if (ft_strstr(tmp, "Plateau"))
		{
			dprintf(FDtest, "%s\n", tmp);
			dprintf(FDtest, "COUCOU\n");
		}
		//dprintf(FDtest, "%s\n", tmp);
	}
	return (0);
}
