/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpointer_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 11:26:42 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 17:31:00 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putpointer_fd(void *value, int fd)
{
	if (value != NULL)
	{
		write(1, "0x", 2);
		ft_putnbr_base_p_fd((uintptr_t)value, "0123456789abcdef", fd);
	}
	else
		write(1, "(nil)", 5);
}
