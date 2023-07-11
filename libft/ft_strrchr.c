/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:33:59 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:34:02 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			index;
	char			*last;
	unsigned char	ch;

	index = 0;
	last = NULL;
	ch = c;
	while (1)
	{
		if (s[index] == ch)
			last = (char *)(s + index);
		if (s[index] == '\0')
			break ;
		index++;
	}
	return (last);
}
