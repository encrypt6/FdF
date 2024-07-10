/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:26:42 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 13:11:48 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putpointer_fd(void *value, int fd)
{
	if (value != NULL)
	{
		write(1, "0x", 2);
		ft_putnbr_base_p_fd((uintptr_t)value, "0123456789abcdef");
	}
	else
		write(1, "(nil)", 5);
}
