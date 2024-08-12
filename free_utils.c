/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:53:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 17:53:09 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map(t_map *map)
{
	t_map	*temp;
	
	while (map)
	{
		temp = map;
		if (temp->line)
		{
			free(temp->line);
			temp->line = (NULL);
		}
		map = map->next;
		free(temp);
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
