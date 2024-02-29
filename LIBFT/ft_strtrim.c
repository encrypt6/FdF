/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:19:55 by elsikira          #+#    #+#             */
/*   Updated: 2024/02/29 17:03:55 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1)
		return (NULL);
	start = 0;
	len = ft_strlen(s1) - 1;
	end = 0;
	if (!set)
		return (NULL);
	while (s1[start] && ft_char_in_set(s1[start], set) == 1)
		start ++;
	while (len > 0 && ft_char_in_set(s1[len], set) == 1)
	{
		len --;
		end ++;
	}
	if (((ft_strlen(s1)) - end == 0) || (s1[start] == '\0'))
		return (ft_strdup(""));
	return (ft_substr(s1, start, (ft_strlen(s1)) - end - start));
}
