/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:21:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 17:30:19 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_nbrlen(int nbr)
{
	size_t	count;

	count = 0;
	if (nbr == 0)
		return (1);
	else if (nbr < 0)
	{
		while (nbr < 0)
		{
			count++;
			nbr /= 10;
		}
	}
	else if (nbr > 0)
	{
		while (nbr > 0)
		{
			count++;
			nbr /= 10;
		}
	}
	return (count);
}
