/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 00:13:46 by elizasikira       #+#    #+#             */
/*   Updated: 2023/11/21 16:31:27 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	size;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	size = ft_strlen(s);
	if (start > size)
		return (ft_strdup(""));
	if (start + len > size)
		len = size - start;
	ptr = ft_calloc((len + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	while (i < len && s[start + i] != 0)
	{
		ptr[i] = s[start + i];
		i++;
	}
	return (ptr);
}
