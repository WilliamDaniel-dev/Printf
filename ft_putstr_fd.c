/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 22:45:12 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/09/21 02:02:15 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL || !fd)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (*s)
	{
		write(fd, s++, sizeof(char));
		i++;
	}
	return (i);
}
