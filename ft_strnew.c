/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:24:16 by mpascaud          #+#    #+#             */
/*   Updated: 2018/04/03 18:28:06 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	*ft_strnew(size_t size)
{
	char	*bla;
	size_t	i;

	i = 0;
	if (!(bla = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		bla[i] = '\0';
		i++;
	}
	bla[i] = '\0';
	return (bla);
}
