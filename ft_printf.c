/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdaniel- <wdaniel-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:48:57 by wdaniel-          #+#    #+#             */
/*   Updated: 2022/10/29 22:46:36 by wdaniel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(char const speci, va_list args)
{
	int	size;

	size = 0;
	if (speci == '%')
		size += ft_putchar_fd('%', 1);
	else if (speci == 's')
		size += ft_putstr_fd(va_arg(args, char *), 1);
	else if (speci == 'c')
		size += ft_putchar_fd(va_arg(args, int), 1);
	else if (speci == 'd' || speci == 'i')
		size += ft_putnbr_fd(va_arg(args, int), 1);
	else if (speci == 'p')
		size += ft_ptr(va_arg(args, unsigned long int));
	else if (speci == 'u')
		size += ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (speci == 'x')
		size += ft_hexa(va_arg(args, unsigned int), 87);
	else if (speci == 'X')
		size += ft_hexa(va_arg(args, unsigned int), 55);
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	size = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			size += specifier(*format, args);
		}
		else
			size += ft_putchar_fd(*format, 1);
		format++;
	}
	va_end(args);
	return (size);
}

/*int		main(void)
{
	ft_printf("--------------------%%c--------------------\n");
	printf("01) LibC PRINTF : |%x|\n", 0);
	ft_printf("01) My PRINTF  : |%x|\n", 0);
	printf("02) LibC PRINTF : |%c|\n", 'A');
	ft_printf("02) My PRINTF  : |%c|\n", 'A');
	
	ft_printf("--------------------%%s--------------------\n");
	printf("01) LibC PRINTF : |%s|\n", "42SP");
	ft_printf("01) My PRINTF  : |%s|\n", "42SP");
	printf("02) LibC PRINTF : |%s|\n", "bits brushing");
	ft_printf("02) My PRINTF  : |%s|\n", "bits brushing");
	printf("03) LibC PRINTF : |%s|\n", "\0\0\0\0\0");
	ft_printf("03) My PRINTF  : |%s|\n", "\0\0\0\0\0");
	
	ft_printf("--------------------%%p--------------------\n");
	printf("01) LibC PRINTF : |%p|\n", "42SP");
	ft_printf("01) My PRINTF  : |%p|\n", "42SP");
	printf("02) LibC PRINTF : |%p|\n", "Let's Code");
	ft_printf("02) My PRINTF  : |%p|\n", "Let's Code");

	ft_printf("----------------%%d-and-%%i----------------\n");
	printf("01) LibC PRINTF : |%d|\n", 42);
	ft_printf("01) My PRINTF  : |%d|\n", 42);
	printf("02) LibC PRINTF : |%i|\n", 42);
	ft_printf("02) My PRINTF  : |%i|\n", 42);
	printf("03) LibC PRINTF : |%d|\n", -42);
	ft_printf("03) My PRINTF  : |%d|\n", -42);
	printf("04) LibC PRINTF : |%i|\n", -42);
	ft_printf("04) My PRINTF  : |%i|\n", -42);
	printf("05) LibC PRINTF : |%i|\n", ' ');
	ft_printf("05) My PRINTF  : |%i|\n", ' ');
	
	ft_printf("--------------------%%%%--------------------\n");
	printf("01) LibC PRINTF : |%%%%%%|\n");
	ft_printf("01) My PRINTF  : |%%%%%%|\n");

	ft_printf("--------------------%%x--------------------\n");
	printf("01) LibC PRINTF : |%x|\n", 42);
	ft_printf("01) My PRINTF  : |%x|\n", 42);
	printf("02) LibC PRINTF : |%x|\n", -42);
	ft_printf("02) My PRINTF  : |%x|\n", -42);
	printf("03) LibC PRINTF : |%x|\n", 123456);
	ft_printf("03) My PRINTF  : |%x|\n", 123456);
	printf("04) LibC PRINTF : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	ft_printf("04) My PRINTF  : |%x| |%x|\n", (unsigned int)-1, UINT_MAX + 1);
	return (0);
}*/
