/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esikira <elsikira@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:55:17 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/16 18:34:28 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	flag_len(const char *format, va_list ap, int fd)
{
	if (*format == 'c')
		return (ft_putchar_fd((char)va_arg(ap, int), fd), 1);
	else if (*format == 's')
		return (ft_putstr_fd(va_arg(ap, char *), fd),
			ft_strlen(va_arg(ap, const char *)));
	else if (*format == 'p')
		return (ft_putpointer_fd(va_arg(ap, void *), fd),
			ft_ptrlen(va_arg(ap, void *)));
	else if ((*format == 'd') || (*format == 'i'))
		return (ft_putnbr_fd(va_arg(ap, int), fd),
			ft_nbrlen(va_arg(ap, int)));
	else if (*format == 'u')
		return (ft_putnbr_fd(va_arg(ap, unsigned int), fd),
			ft_nbrlen(va_arg(ap, unsigned int)));
	else if (*format == 'x')
		return (ft_putnbr_base_fd(va_arg(ap, unsigned long),
				"0123456789abcdef", fd),
			ft_hexlen(va_arg(ap, unsigned long)));
	else if (*format == 'X')
		return (ft_putnbr_base_fd(va_arg(ap, unsigned long),
				"0123456789ABCDEF", fd),
			ft_hexlen(va_arg(ap, unsigned long)));
	else if (*format == '%')
		return (ft_putchar_fd('%', fd), 1);
	return (0);
}

int	ft_dprintf(int fd, const char *formatt, ...)
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
			len += flag_len(&formatt[i], ap, fd);
		}
		else
		{
			ft_putchar_fd(formatt[i], fd);
			len += 1;
		}
		i++;
	}
	va_end(ap);
	return (len);
}
