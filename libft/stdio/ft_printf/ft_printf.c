/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizasikira <elizasikira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:55:17 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 17:58:10 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_mandat(const char *format, va_list ap)
{
	size_t len;

	len = 0;
	if (*format == 'c')
		len += ft_strlen(ft_putchar_fd((char)va_arg(ap, int), STDOUT_FILENO));
	else if (*format == 's')
		len += ft_strlen(ft_putstr_fd(va_arg(ap, char *), STDOUT_FILENO));
	else if (*format == 'p')
		len += ft_strlen(ft_putpointer_fd(va_arg(ap, void *), STDOUT_FILENO));
	else if (*format == 'd')
		len += ft_nbrlen(ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO));
	else if (*format == 'i')
		len += ft_nbrlen(ft_putnbr_fd(va_arg(ap, int), STDOUT_FILENO));
	else if (*format == 'u')
		len += ft_nbrlen(ft_putnbr_fd(va_arg(ap, unsigned int), STDOUT_FILENO));
	else if (*format == 'x')
		len += ft_nbrlen(ft_putnbr_base_fd(va_arg(ap, unsigned long), "0123456789abcdef", STDOUT_FILENO));
	else if (*format == 'X')
		len += ft_nbrlen(ft_putnbr_base_fd(va_arg(ap, unsigned long), "0123456789ABCDEF", STDOUT_FILENO));
	else if (*format == '%')
		len += ft_strlen(ft_putchar_fd('%', STDOUT_FILENO));
	return (len);
}

int	ft_printf(const char *formatt, ...)
{
	va_list	ap;
	size_t	i;
	int		len;

	i = 0;
	len = 0;
	if (formatt == NULL)
		return (-1);
	va_start(ap, formatt);
	while (i < ft_strlen(formatt))
	{
		if (formatt[i] == '%')
		{
			i++;
			len += ft_mandat(&formatt[i], ap);
		}
		else
			len += ft_strlen(ft_putchar_fd(formatt[i], STDOUT_FILENO));
		i++;
	}
	va_end(ap);
	return (len);
}
