/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   letter_conditionals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:15:45 by ltalia            #+#    #+#             */
/*   Updated: 2021/11/09 19:15:48 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_i_or_d(va_list arg)
{
	int		i;
	char	*str;
	int		size;

	i = va_arg(arg, int);
	str = ft_itoa(i);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free (str);
	return (size);
}

int	ft_print_p(va_list arg)
{
	unsigned long	p;
	char			*str;
	int				size;

	p = va_arg(arg, unsigned long);
	str = ft_convert_hex3(p);
	write (1, "0x", 2);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str) + 2;
	free (str);
	return (size);
}

int	ft_print_u(va_list arg)
{
	unsigned int	u;
	char			*str;
	int				size;

	u = va_arg(arg, unsigned int);
	str = ft_utoa(u);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int	ft_print_x(va_list arg)
{
	unsigned int	x;
	char			*str;
	int				size;

	x = va_arg(arg, unsigned int);
	str = ft_convert_hex(x);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}

int	ft_print_x2(va_list arg)
{
	unsigned int	x2;
	char			*str;
	int				size;

	x2 = va_arg(arg, unsigned int);
	str = ft_convert_hex2(x2);
	ft_putstr_fd(str, 1);
	size = ft_strlen(str);
	free(str);
	return (size);
}
