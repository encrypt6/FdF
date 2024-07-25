/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esikira <elsikira@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:55:17 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 16:33:38 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	flag_cs(const char *format, va_list ap, int fd)
{
	char	c;
	char	*str;

	if (*format == 'c')
	{
		c = (char)va_arg(ap, int);
		return (ft_putchar_fd(c, fd), 1);
	}
	if (*format == 's')
	{
		str = va_arg(ap, char *);
		if (str)
		{
			ft_putstr_fd(str, fd);
			return (ft_strlen(str));
		}
		else
		{
			ft_putstr_fd("(null)", fd);
			return (6);
		}
	}
	return (0);
}

int	flag_diu(const char *format, va_list ap, int fd)
{
	int				d;
	int				i;
	unsigned int	u;

	d = va_arg(ap, int);
	i = va_arg(ap, int);
	u = va_arg(ap, unsigned int);
	if (*format == 'd')
		return (ft_putnbr_fd(d, fd), ft_nbrlen(d));
	else if (*format == 'i')
		return (ft_putnbr_fd(i, fd), ft_nbrlen(i));
	else if (*format == 'u')
	{
		ft_putnbr_base_fd(u, "0123456789", fd);
		return (ft_nbrlen(u));
	}
	return (0);
}

int	flag_pxx(const char *format, va_list ap, int fd)
{
	void			*p;
	unsigned long	x;
	unsigned long	big_x;

	p = va_arg(ap, void *);
	x = va_arg(ap, unsigned long);
	big_x = va_arg(ap, unsigned long);
	if (*format == 'p')
	{
		ft_putpointer_fd(p, fd);
		return (ft_ptrlen(p));
	}
	else if (*format == 'x')
	{
		ft_putnbr_base_fd(x, "0123456789abcdef", fd);
		return (ft_hexlen(x));
	}
	else if (*format == 'X')
	{
		ft_putnbr_base_fd(big_x, "0123456789ABCDEF", fd);
		return (ft_hexlen(big_x));
	}
	return (0);
}

int	flag_apply(const char *format, va_list ap, int fd)
{
	if (*format == 'c' || *format == 's')
		return (flag_cs(format, ap, fd));
	else if (*format == 'd' || *format == 'i'
		|| *format == 'u')
		return (flag_diu(format, ap, fd));
	else if (*format == 'p' || *format == 'x'
		|| *format == 'X')
		return (flag_pxx(format, ap, fd));
	else if (*format == '%')
	{
		ft_putchar_fd('%', fd);
		return (1);
	}
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
			len += flag_apply(&formatt[i], ap, fd);
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
