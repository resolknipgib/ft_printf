/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltalia <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 19:15:12 by ltalia            #+#    #+#             */
/*   Updated: 2021/11/09 19:15:16 by ltalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

int		ft_printf(const char *str, ...);
char	*ft_convert_hex(unsigned int x);
char	*ft_convert_hex2(unsigned int x2);
char	*ft_convert_hex3(unsigned long p);
char	*ft_utoa(unsigned int n);
int		ft_print_s(va_list arg);
int		ft_print_c(va_list arg);
int		ft_print_i_or_d(va_list arg);
int		ft_print_p(va_list arg);
int		ft_print_u(va_list arg);
int		ft_print_x(va_list arg);
int		ft_print_x2(va_list arg);

#endif
