/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:37:30 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/10 17:27:45 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*check_malloc(void *malloced_val)
{
	if (malloced_val == NULL)
	{
		perror("Error");
		return (NULL);
		exit(1);
	}
	else
		return (0);
}
