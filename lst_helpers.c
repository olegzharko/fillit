/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 11:35:53 by ozharko           #+#    #+#             */
/*   Updated: 2017/12/14 13:54:28 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

t_solution		*new_solution_element(t_figure *figure, int x, int y)
{
	t_solution	*result;

	result = (t_solution*)malloc(sizeof(t_solution));
	result->figure = figure;
	result->next = NULL;
	result->previous = NULL;
	result->x = x;
	result->y = y;
	return (result);
}

char			*ft_strsub(char const *s, size_t start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!s)
		return (NULL);
	substr = (char*)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
