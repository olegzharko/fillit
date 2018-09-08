/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:24:23 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 11:24:31 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <string.h>
#include "libfil.h"

void		put_bits(char *tetr, t_figure *figure)
{
	unsigned short int		i;
	unsigned short int		j;
	int						a;
	int						tetr_first_x;
	int						tetr_last_x;

	tetr_first_x = 4;
	tetr_last_x = 0;
	i = 0;
	j = 0;
	a = 0;
    while (a++ < 21)
    {
        if (*tetr == '\n')
			figure->data[i] ? figure->y_size++ : 0;
        else if (*tetr == '#')
        {
			tetr_first_x = (a % 5 < tetr_first_x) ? a % 5 : tetr_first_x;
			tetr_last_x = (a % 5 > tetr_last_x) ? a % 5 : tetr_last_x;
            figure->data[i] |= ft_pow(2, 15 - j);
        }
		i = (*tetr == '\n') ? i + 1 : i;
		j = (*tetr == '\n') ? 0 : (j + 1);
		tetr++;
    }
	figure->x_size = tetr_last_x -tetr_first_x + 1;
}

int			is_valid(char *res)
{
	int		i;
	int		dot;
	int		hash;
	int		count_hash;

	i = 0;
	dot = 0;
	hash = 0;
	count_hash = 0;
	while (res[i] == '.' || res[i] == '#' || res[i] == '\n')
	{
		if (res[i] == '#')
			if (res[i] == '#' && ((i < 19 && res[i + 1] == '#') ||
			((i >= 1) && res[i - 1] == '#') ||
			((i < 16) && res[i + 5] == '#') || ((i > 5) && res[i - 5] == '#')))
				count_hash++;
		if (res[i] == '#')
			hash++;
		if (res[i] == '.')
			dot++;
		i++;
	}
	if (hash == 4 && dot == 12 && count_hash == 4)
		return (1);
	return (0);
}

t_figure	*new_figure_element(char letter)
{
	unsigned short int		*data;
	t_figure				*result;

	result = (t_figure*)malloc(sizeof(t_figure));
	result->letter = letter;
	result->next = NULL;
	result->previous = NULL;
	result->x_size = 0;
	result->y_size = 0;
	data = (unsigned short int*)malloc(sizeof(unsigned short int) * 4);
	bzero(data, sizeof(unsigned short int) * 4);
	result->data = data;
	return (result);
}

t_figure	*link_figure(t_figure *head, t_figure *last)
{
	t_figure *f_iterator;

	f_iterator = head;
	while (f_iterator->next != NULL)
		f_iterator = f_iterator->next;
	f_iterator->next = last;
	last->previous = f_iterator;
	return (head);
}

void		dispatch_invalid_figure(void)
{
	ft_putstr("NOT VALID FIGURE\n");
	exit(0);
}

t_figure	*individual_cut(char *buf, int red, int n)
{
	char		i;
	char		*fig;
	t_figure	*ret_head;
	t_figure	*figure;
	t_figure	*ret;

	ret = NULL;
	i = 'A';
	while (n <= red)
	{
		figure = new_figure_element(i++);
		n = n + 21;
		fig = ft_strsub(buf, n - 21, 21);
		if (!is_valid(fig))
			dispatch_invalid_figure();
		put_bits(fig, figure);
		if (ret == NULL)
			ret_head = figure;
		else
			link_figure(ret, figure);
		ret = (ret == NULL) ? figure : ret->next;
	}
	return (ret_head);
}

t_figure	*read_all(int fd)
{
	char		buf[545];
	int			red;
	int			n;

	n = 0;
	red = read(fd, &buf, 545);
	if (red == -1 || red < 20 || red > 545 || red % 21 != 20)
		exit(0);
	buf[red] = '\n';
	return (individual_cut(buf, red, n));
}
