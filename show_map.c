/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 10:58:46 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:54:49 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

void		ptint_map(int map_size, char **show)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < map_size)
	{
		while (j < map_size)
			write(1, &show[i][j++], 1);
		write(1, "\n", 1);
		i++;
		j = 0;
	}
}

void		prepare_bit_figure(t_solution *solu, t_figure *figu, char **show)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (solu)
	{
		while (figu->data[j])
		{
			figu->data[j] = figu->data[j] >> solu->x;
			while (i < 16)
			{
				if ((figu->data[j] >> (15 - i)) % 2)
					show[solu->y + j][i] = solu->figure->letter;
				i++;
			}
			i = 0;
			j++;
		}
		j = 0;
		i = 0;
		figu = figu->next;
		solu = solu->next;
	}
}

void		show_map(t_solution *solution, t_figure *figure, int map_size)
{
	char	**show;
	int		i;
	int		j;

	i = 0;
	show = (char **)malloc(sizeof(char *) * (map_size));
	while (i < map_size)
		show[i++] = (char *)malloc(sizeof(char ) * (map_size));
	i = 0;
	j = 0;
	while (i < map_size)
	{
		while (j < map_size)
			show[i][j++] = '.';
		show[i][j] = '\n';
		i++;
		j = 0;
	}
	prepare_bit_figure(solution, figure, show);
	ptint_map(map_size, show);
}
