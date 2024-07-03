/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 13:51:35 by elsikira          #+#    #+#             */
/*   Updated: 2024/06/15 14:08:11 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int ft_mandat(const char *format, va_list ap)
{
	int len;

	len = 0;
	if (*format == 'c');
		len += ft_putchar((char)va_arg(ap, int));
	else if (*format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (*format == 'p')
		len += ft_is_p(va_arg(ap, void *));
	else if (*format == 'd')
		len += ft_putnbr(va_arg(ap, int));
	else if (*format == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (*format == 'u')
		len += ft_putnbr(va_arg(ap, unsigned int));
	else if (*format == 'x')
		len += ft_putnbr_base(va_arg(ap, unsigned long), "0123456789abcdef");
	else if (*format == 'X')
		len += ft_putnbr_base(va_arg(ap, unsigned long), "0123456789ABCDEF");
	else if (*format == '%')
		len += ft_putchar('%');
	return (len);
}
