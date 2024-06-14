/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 15:10:19 by elsikira          #+#    #+#             */
/*   Updated: 2023/11/21 11:12:43 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (i < len && big[i])
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j] && big[i + j] != '\0')
		{
			j++;
			if (j == ft_strlen(little))
				return ((char *)(big) + i);
		}
		i++;
	}
	return (NULL);
}
