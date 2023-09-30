/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:55:16 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/10/30 00:19:52 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# ifdef __APPLE__
#  define OSNULL "0x0"
# else
#  define OSNULL "(nil)"
# endif

int			ft_numsize(unsigned long int num);
size_t		ft_strlen(const char *s);
int			ft_putstr_fd(char *s, int fd);
int			ft_putnbr_fd(long n, int fd);
int			ft_putchar_fd(char c, int fd);
int			ft_ptr(unsigned long int n);
int			ft_hexa(unsigned long c, int ascii);
void		ft_swapp(char *str);
int			specifier(char const speci, va_list args);
int			ft_printf(const char *format, ...);

#endif
