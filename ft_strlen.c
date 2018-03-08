/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpascaud <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:22:26 by mpascaud          #+#    #+#             */
/*   Updated: 2018/03/08 16:23:05 by mpascaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "filler.h"

size_t      ft_strlen(const char *s)
{
	size_t      i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		i++;
	}
	return (i);
}

