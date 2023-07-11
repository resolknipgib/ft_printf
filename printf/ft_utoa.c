/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:15:27 by ltalia            #+#    #+#             */
/*   Updated: 2021/11/09 19:15:32 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_count(unsigned int n)
{
	int	count;

	count = 1;
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_loop(char *str, unsigned int n, unsigned int count)
{
	if (n >= 10)
		ft_loop(str, n / 10, count - 1);
	str[count] = (n % 10) + 48;
}

char	*ft_utoa(unsigned int n)
{
	char				*str;
	unsigned int		count;

	count = ft_count(n);
	str = (char *) malloc (sizeof(char) * count + 1);
	if (str == NULL)
		return (NULL);
	ft_loop(str, n, count - 1);
	str[count] = '\0';
	return (str);
}
