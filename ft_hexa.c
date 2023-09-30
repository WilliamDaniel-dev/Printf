/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 20:24:08 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/10/28 23:47:16 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_swapp(char *str)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (j > i)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
}

int	ft_hexa(unsigned long c, int ascii)
{
	int		leftover;
	int		i;
	char	*resul;

	i = 0;
	if (!c)
		return (ft_putchar_fd('0', 1));
	resul = malloc(ft_numsize(c) + 1);
	leftover = 0;
	while (c != 0)
	{
		leftover = c % 16;
		if (leftover < 10)
			resul[i++] = leftover + 48;
		else
			resul[i++] = leftover + ascii;
		c /= 16;
	}
	resul[i] = '\0';
	ft_swapp(resul);
	i = ft_putstr_fd(resul, 1);
	free(resul);
	return (i);
}

int	ft_ptr(unsigned long int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putstr_fd(OSNULL, 1);
	else
	{
		i += ft_putstr_fd("0x", 1);
		i += ft_hexa(n, 87);
	}
	return (i);
}
