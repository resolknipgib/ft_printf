/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:37:59 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:38:05 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_check_and_free_array(char **array)
{
	size_t	i;
	size_t	flag;

	flag = 0;
	i = 0;
	while (array[i])
	{
		if (array[i] == NULL)
			flag = 1;
		i++;
	}
	if (flag == 1)
	{
		i = 0;
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	return (array);
}

static size_t	ft_find_count(char const *s, char c)
{
	size_t	index;
	size_t	count;
	size_t	length;

	index = 0;
	count = 0;
	length = 0;
	while (s[index])
	{
		if (s[index] == c)
		{
			if (length != 0)
				count++;
			length = 0;
		}
		else
			length++;
		index++;
	}
	if (length != 0)
		return (count + 1);
	else
		return (count);
}

static void	ft_just_do(char const *s, char c, char **array,
										size_t count)
{
	size_t	array_index;
	size_t	index;
	size_t	length;

	array_index = 0;
	index = 0;
	length = 0;
	while (array_index < count)
	{
		if (s[index] == c || s[index] == '\0')
		{
			if (length != 0)
			{
				array[array_index] = ft_calloc(length + 1, sizeof(char));
				if (array[array_index] == NULL)
					return ;
				ft_memcpy(array[array_index], s + index - length, length);
				array_index++;
			}
			length = 0;
		}
		else
			length++;
		index++;
	}
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**array;

	if (s == NULL)
		return (NULL);
	count = ft_find_count(s, c);
	array = ft_calloc(count + 1, sizeof(char *));
	if (array == NULL)
		return (NULL);
	ft_just_do(s, c, array, count);
	ft_check_and_free_array(array);
	array[count] = NULL;
	return (array);
}
