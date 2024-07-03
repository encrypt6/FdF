/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elizasikira <elizasikira@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:55:17 by elsikira          #+#    #+#             */
/*   Updated: 2024/06/15 13:57:08 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_is_p(void *value)
{
	int	len;

	len = 0;
	if (value != NULL)
	{
		write(1, "0x", 2);
		len = ft_putnbr_basep((uintptr_t)value, "0123456789abcdef") + 2;
	}
	else
	{
		len = write(1, "(nil)", 5);
	}
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
			len += ft_putchar(formatt[i]);
		i++;
	}
	va_end(ap);
	return (len);
}
// int	main(void)
// {
// 	ft_printf("%c%c\n", 'a', 'b');
// }
