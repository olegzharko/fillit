/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 12:47:23 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 12:47:38 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"
#include <string.h>

t_solution		*put_figure(t_figure *fgr, int *map, int x, int y, int m_lngth)
{
	int			check_result;

	check_result = check_figure(map, fgr, x, y, m_lngth);
	while (!check_result && y < m_lngth)
	{
		if (x < m_lngth)
			x++;
		else
		{
			x = 0;
			y++;
		}
		check_result = check_figure(map, fgr, x, y, m_lngth);
	}
	if (check_result)
	{
		insert_figure(map, fgr, x, y);
		return (new_solution_element(fgr, x, y));
	}
	return (NULL);
}

int shift_figure(t_solution* solution, int *map, int m_length, int from_begin)
{
	int x;
	int y;
	t_solution *result;

	result = NULL;
	x = solution->x;
	y = solution->y;
	if (!from_begin)
		delete_figure(map, solution);
	if (from_begin)
	{
		x = 0;
		y = 0;
	}
	else if (x < m_length)
		x++;
	else
	{
		x = 0;
		y++;
	}
	result = put_figure(solution->figure, map, x, y, m_length);
	if (result != NULL)
	{
		solution->x = result->x;
		solution->y = result->y;
	}
	//TODO result memory leak fix!!!
	return (result != NULL);
}

int backtrack(t_solution *solution, int *map, int m_length)
{
	int from_begin = 0;
	while (!shift_figure(solution, map, m_length, from_begin))
	{
		if (solution->previous == NULL)
			return (0);
		if (!backtrack(solution->previous, map, m_length))
			return (0);
		from_begin = 1;
	}
	return (1);
}

int				fill_map(t_figure *fgr, int *map, t_solution *sltn, int m_lng)
{
	t_solution	*last_put_figure;

	while (NULL != sltn->next)
		sltn = sltn->next;
	last_put_figure = put_figure(fgr, map, 0, 0, m_lng);
	if (last_put_figure != NULL)
	{
		sltn->next = last_put_figure;
		last_put_figure->previous = sltn;
		return (1);
	}
	while (last_put_figure == NULL)
	{
		if (backtrack(sltn, map, m_lng))
		{
			last_put_figure = put_figure(fgr, map, 0, 0, m_lng);
			if (last_put_figure == NULL)
				continue ;
			sltn->next = last_put_figure;
			last_put_figure->previous = sltn;
		}
		else
			break ;
	}
	return (last_put_figure != NULL);
}

int				proc_fgrs(int *map, int m_lng, t_figure *fgr, t_solution **sltn)
{
	t_figure	*first_figure;
	int			is_map_enough;

	first_figure = fgr;
	*sltn = new_solution_element(fgr, 0, 0);
	insert_figure(map, fgr, 0, 0);
	fgr = fgr->next;
	is_map_enough = 1;
	while (fgr != NULL && is_map_enough)
	{
		is_map_enough = fill_map(fgr, map, *sltn, m_lng);
		fgr = fgr->next;
	}
	if (is_map_enough)
	{
		return (m_lng);
	}
	map = increase_map(map, m_lng);
	return (proc_fgrs(map, ++m_lng, first_figure, sltn));
}
