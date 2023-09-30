/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 05:22:44 by mflavio-          #+#    #+#             */
/*   Updated: 2022/10/28 04:09:49 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_numsize(unsigned long int num)
{
	int	count;

	count = 0;
	if (num <= 0)
		count++;
	while (num != 0)
	{
		num = num / 10;
		count++;
	}
	return (count);
}
