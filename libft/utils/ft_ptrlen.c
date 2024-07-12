/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 17:04:26 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/12 18:04:23 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_ptrlen(void *ptr)
{
	uintptr_t	address;
	int		digits = 0;

	address = (uintptr_t)ptr;
	while (address != 0)
	{
		digits++;
		address /= 16;
	}
	return (digits + 2);
}
