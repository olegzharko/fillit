/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_map_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:36:18 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:55:55 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libfil.h"
#include <string.h>

int				check_figure(int *map, t_figure *fgr, int x, int y, int m_len)
{
	int			i;
	int			current_line;

	i = 0;
	if (x + fgr->x_size > m_len)
	{
		return (0);
	}
	while (i < fgr->y_size)
	{
		current_line = fgr->data[i];
		current_line = current_line >> x;
		current_line = ~current_line;
		if ((y + i >= m_len) || (map[y + i] & current_line) != map[y + i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void			insert_figure(int *map, t_figure *figure, int x, int y)
{
	int			i;
	int			current_line;

	i = 0;
	while (i < figure->y_size)
	{
		current_line = figure->data[i];
		current_line = current_line >> x;
		map[y + i] |= current_line;
		i++;
	}
}

void			delete_figure(int *map, t_solution *putted_figure)
{
	int			i;
	int			x;
	int			y;
	t_figure	*figure;
	int			current_line;

	i = 0;
	x = putted_figure->x;
	y = putted_figure->y;
	figure = putted_figure->figure;
	while (i < figure->y_size)
	{
		current_line = figure->data[i];
		current_line = current_line >> x;
		current_line = ~current_line;
		map[y + i] &= current_line;
		i++;
	}
}

int				*increase_map(int *map, int m_length)
{
	int			*result;

	free(map);
	++m_length;
	result = (int *)malloc(sizeof(int) * m_length);
	bzero(result, sizeof(int) * m_length);
	return (result);
}

int				calc_map_size(t_figure *fgrs)
{
	int			figure_count;
	int			map_size;
	int			frst_fgr_mx_sz;

	figure_count = 0;
	frst_fgr_mx_sz = fgrs->x_size > fgrs->y_size ? fgrs->x_size : fgrs->y_size;
	while (fgrs != NULL)
	{
		fgrs = fgrs->next;
		figure_count++;
	}
	map_size = sqrtabove(figure_count * 4);
	map_size = frst_fgr_mx_sz > map_size ? frst_fgr_mx_sz : map_size;
	return (map_size);
}
