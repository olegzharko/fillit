/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_figure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 10:59:40 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:53:46 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

void	step_up(t_figure *head_figure)
{
	int		i;

	i = 0;
	while (i < 3)
	{
		if (head_figure->data[i] == 0)
		{
			head_figure->data[i] = head_figure->data[i + 1];
			if (i < 3)
				head_figure->data[i + 1] = 0;
		}
		i++;
	}
}

void	cut_figure(t_figure *head_figure)
{
	int		i;

	i = 0;
	while (head_figure)
	{
		while (head_figure->data[0] == 0)
			step_up(head_figure);
		i = 0;
		while (i < 4)
		{
			ft_print_bits(head_figure->data[i]);
			i++;
		}
		head_figure = head_figure->next;
	}
}

void	bit_left(t_figure *head_figure)
{
	int						i;
	unsigned short int		res;
	unsigned short int		tmp;
	int						count;

	i = 0;
	res = 0;
	count = 0;
	while (i < 4)
	{
		if (head_figure->data[i] > res)
			res = head_figure->data[i];
		i++;
	}
	i = 0;
	while (i++ < 4)
	{
		tmp = res;
		res = res << 1;
		(res > tmp) ? count++ : 0;
	}
	i = 0;
	if (count)
		while (i++ < 4)
			head_figure->data[i - 1] = head_figure->data[i - 1] << count;
}

void	change_figure(t_figure *head_figure)
{
	t_figure	*start;

	start = head_figure;
	while (head_figure)
	{
		bit_left(head_figure);
		head_figure = head_figure->next;
	}
	cut_figure(start);
}
