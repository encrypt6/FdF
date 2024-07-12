/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:26:25 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/12 18:04:12 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_hexlen(unsigned int hex)
{
	uintptr_t	address;
	int		digits = 0;

	address = hex;
	while (address != 0)
	{
		digits++;
		address /= 16;
	}
	return (digits);
}
