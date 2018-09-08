/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 13:09:13 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:54:08 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int			sqrtabove(int n)
{
	int		result;

	result = 0;
	while (result * result < n)
		result++;
	return (result);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *s)
{
	while (*s != 0)
		ft_putchar(*s++);
}

int			ft_pow(int x, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	return (x * ft_pow(x, power - 1));
}

void		ft_print_bits(unsigned short int bit)
{
	unsigned short int	i;

	i = 0;
	while (i < 16)
	{
		if ((bit >> (15 - i)) % 2)
			ft_putchar('1');
		else
			ft_putchar('0');
		i++;
	}
	ft_putchar('\n');
}
