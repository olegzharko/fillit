/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:02:27 by ozharko           #+#    #+#             */
/*   Updated: 2017/11/17 12:02:28 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

int			main(void)
{
	char	*input;

	input = read_term();
	if (input == NULL)
		printf("the tetriminos is invalid");
	return (0);
}
