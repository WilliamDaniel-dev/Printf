/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:50:23 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/18 20:20:44 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_fd(long n, int fd)
{
	char	num;
	int		len;

	num = 0;
	len = 0;
	if (n >= 10)
	{
		num = n % 10 + '0';
		n /= 10;
		len += ft_putnbr_fd(n, fd);
		len += write(1, &num, 1);
	}
	else if (0 <= n && n <= 9)
	{
		n += '0';
		len += write(1, &n, 1);
	}
	else if (n < 0)
	{
		n *= (-1);
		len += write(1, "-", 1);
		len += ft_putnbr_fd(n, fd);
	}
	return (len);
}
