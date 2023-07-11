/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:35:52 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:35:54 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check_c_in_set(char c, const char *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static size_t	ft_find_boundary(const char *str, const char *set,
													size_t length, char step)
{
	size_t	bound;
	size_t	index;

	bound = 0;
	while (bound < length)
	{
		index = bound;
		if (step == -1)
			index = length - 1 - bound;
		if (!ft_check_c_in_set(str[index], set))
			return (index);
		bound++;
	}
	return (bound);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	length;
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (NULL);
	length = ft_strlen(s1);
	start = ft_find_boundary(s1, set, length, 1);
	end = ft_find_boundary(s1, set, length, -1);
	length = end - start + 1;
	str = ft_calloc(length + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s1 + start, length);
	str[length] = '\0';
	return (str);
}
