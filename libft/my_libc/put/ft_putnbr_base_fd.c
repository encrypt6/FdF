/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:06:44 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 12:09:31 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(unsigned int nbr, char *base, int fd)
{
	long long	i;
	char		result [100];

	if (nbr == 0)
		ft_putchar_fd(base[0], fd);
	i = 0;
	while (nbr > 0)
	{
		result[i] = base[nbr % ft_strlen(base)];
		nbr /= ft_strlen(base);
		i++;
	}
	while (i > 0)
		ft_putchar_fd(result[i-- - 1], fd);
}
