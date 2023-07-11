/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:34:45 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:34:48 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char	*dest;
	char	*source;
	size_t	lendst;
	size_t	temp;

	dest = dst;
	source = (char *)src;
	temp = dstsize;
	while (temp-- != 0 && *dest != '\0')
		dest++;
	lendst = dest - dst;
	temp = dstsize - lendst;
	if (temp == 0)
		return (lendst + ft_strlen(source));
	while (*source != '\0')
	{
		if (temp > 1)
		{
			*dest++ = *source;
			temp--;
		}
		source++;
	}
	*dest = '\0';
	return (lendst + (source - src));
}
