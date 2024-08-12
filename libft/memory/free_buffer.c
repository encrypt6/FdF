/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 19:55:52 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 19:59:01 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	free_buffer(char **buffer)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		if (buffer[i])
		{
			free(buffer[i]);
			buffer[i] = (NULL);
		}
		i++;
	}
}
