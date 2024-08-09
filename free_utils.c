/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:53:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/10 00:21:31 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	t_map	*current;
	t_map	*next;

	if (map == NULL || map == (t_map *)1)
		return ;
	current = map;
	while (current)
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
}

void	free_points(int height, t_point **points)
{
	int	i;

	i = 0;
	while (i < height)
	{
		free(points[i]);
		i++;
	}
	free(points);
}

void	free_split(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
