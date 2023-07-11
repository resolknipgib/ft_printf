/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 13:39:01 by ltalia            #+#    #+#             */
/*   Updated: 2021/10/24 13:39:03 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned char	*str;

	if (s == NULL)
		return ;
	str = (unsigned char *)s;
	while (*str)
	{
		ft_putchar_fd(*str, fd);
		str++;
	}
}
