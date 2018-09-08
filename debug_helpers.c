/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:08:43 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:53:37 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libfil.h"

void		print_map(int *map, int m_length)
{
	int		i;

	i = 0;
	if (map == NULL)
	{
		ft_putstr("ERROR\n");
		return ;
	}
	while (i < m_length)
	{
		ft_print_bits(map[i]);
		i++;
	}
}

void		print_figures(t_figure *figures)
{
	int		i;

	while (figures != NULL)
	{
		i = 0;
		while (i < figures->y_size)
		{
			ft_print_bits(figures->data[i]);
			i++;
		}
		figures = figures->next;
	}
}
