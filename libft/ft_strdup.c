/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:35:06 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:35:08 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	length;
	char	*array;

	length = ft_strlen(s1);
	array = ft_calloc(length + 1, sizeof(char));
	if (array == NULL)
		return (NULL);
	ft_memcpy(array, s1, length);
	array[length] = '\0';
	return (array);
}
