/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:14:53 by ltalia            #+#    #+#             */
/*   Updated: 2021/11/09 19:15:02 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_set_char(const char ch, const char *set)
{
	while (*set)
	{
		if (*set == ch)
			return (1);
		set++;
	}
	return (0);
}

int	ft_print_c(va_list arg)
{
	int	c;

	c = va_arg(arg, int);
	write (1, &c, 1);
	return (1);
}

int	ft_print_s(va_list arg)
{
	char	*s;
	int		size;

	s = va_arg(arg, char *);
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(s, 1);
	size = ft_strlen(s);
	return (size);
}

int	ft_get_the_letter(char letter, va_list arg)
{
	int	size;

	size = 1;
	if (letter == '%')
		write (1, "%%", 1);
	if (letter == 'c')
		size = ft_print_c(arg);
	if (letter == 's')
		size = ft_print_s(arg);
	if (letter == 'p')
		size = ft_print_p(arg);
	if (letter == 'i' || letter == 'd')
		size = ft_print_i_or_d(arg);
	if (letter == 'u')
		size = ft_print_u(arg);
	if (letter == 'x')
		size = ft_print_x(arg);
	if (letter == 'X')
		size = ft_print_x2(arg);
	return (size);
}

int	ft_printf(const char *str, ...)
{
	int		count;
	int		size;
	va_list	arg;

	count = 0;
	size = 0;
	va_start (arg, (char *)str);
	while (str[count] != '\0')
	{
		if (str[count] == '%')
		{
			count++;
			if (!ft_is_set_char(str[count], "cspdiuxX%"))
				continue ;
			size += ft_get_the_letter(str[count], arg);
		}
		else
			size += write (1, &str[count], 1);
		count++;
	}
	va_end(arg);
	return (size);
}
