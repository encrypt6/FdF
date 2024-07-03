/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 15:31:31 by elsikira          #+#    #+#             */
/*   Updated: 2024/06/15 14:04:47 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	long long	i;
	char		result [100];
	int			len;

	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	while (nbr > 0)
	{
		result[i] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

int	ft_putnbr_basep(unsigned long nbr, char *base)
{
	long long	i;
	char		result [100];
	int			len;

	if (nbr == 0)
	{
		ft_putchar(base[0]);
		return (1);
	}
	i = 0;
	if (nbr < 0)
	{
		ft_putchar('-');
		nbr *= -1;
	}
	while (nbr > 0)
	{
		result[i] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		i++;
	}
	len = i;
	while (i > 0)
		ft_putchar(result[i-- - 1]);
	return (len);
}

int	ft_putnbr(long long nbr)
{
	int	len;

	len = 0;
	if (nbr < 0)
	{
		len += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < 10)
	{
		len += ft_putchar(nbr + '0');
	}
	else
	{
		len += ft_putnbr(nbr / 10);
		len += ft_putnbr(nbr % 10);
	}
	return (len);
}
