/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_p_fd.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:10:38 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 13:10:37 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_p_fd(unsigned long nbr, char *base, int fd)
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
