/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:33:55 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:54:39 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libfil.h"

int		main(int argc, char **argv)
{
	int			map_size;
	int			*map;
	int			fd;
	t_figure	*figures;
	t_solution	*solution;

	if (argc != 2)
	{
		ft_putstr("\n usage: fillit input_file\n");
		return (0);
	}
	solution = NULL;
	fd = open(argv[1], O_RDONLY);
	figures = read_all(fd);
	change_figure(figures);
	map_size = calc_map_size(figures);
	map = (int*)malloc(sizeof(int) * map_size);
	map_size = proc_fgrs(map, map_size, figures, &solution);
	show_map(solution, figures, map_size);
	return (0);
}
