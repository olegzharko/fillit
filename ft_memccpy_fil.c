/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_fil.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozharko <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:45:52 by ozharko           #+#    #+#             */
/*   Updated: 2017/10/30 17:46:32 by ozharko          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfil.h"

void		*ft_memcpy_fil(void *dst, const void *src, size_t n)
{
	char	*dst_copy;
	char	*src_copy;

	if (dst == NULL || src == NULL)
		return (0);
	dst_copy = (char *)dst;
	src_copy = (char *)src;
	while (n > 0)
	{
		*dst_copy = *src_copy;
		src_copy++;
		dst_copy++;
		n--;
	}
	return (dst);
}
