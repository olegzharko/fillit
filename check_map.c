/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:02:27 by ozharko           #+#    #+#             */
/*   Updated: 2017/11/17 12:02:28 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

char		*is_term(char *res, int term)
{
	int		i;
	int		hash;
	int 	count_hash;

	i = 0;
	hash = term * 4;
	while (res[i])
	{
		if (res[i] == '#')
			if (res[i + 1] == '#' || res[i + 5] == '#' || res[i - 1] == 1 || res[i - 5] == '#' )
				count_hash++;
			// не хватает проверки на соседний термин за $$
		i++;
	}
	if (hash == count_hash)
		return (res);
	return (0);
}

char		*is_valid(char *res)
{
	int		i;
	int		dot;
	int		hash;
	int		term;

	i = 0;
	dot = 0;
	hash = 0;
	while (res[i] == '.' || res[i] == '#' || res[i] == '\n')
	{	
		i++;
		hash++;
		dot++;
	}
	term = i / 21;
	if (res[i] == '\0' && hash == 4 * term && dot == 12 * term)
		is_term(res, term);///////////
	else
		res = NULL;
	return (res);
}

char		*read_all(void)
{
	char	buf[1];
	char	all[572];
	char	*res;
	int		i;

	i = 0;
	while (read(0, buf, 1))
		all[i++] = buf[0];
	all[i] = '\0';
	ft_memcpy_fil(res, all, i);
	is_valid(res);
	return (res);

}

char 		*read_term(void)
{
	char	*input;

	input = read_all();
	printf("%s\n", input);
	return (input);
}



