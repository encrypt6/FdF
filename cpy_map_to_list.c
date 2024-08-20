/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:23:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/20 14:47:16 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*create_nodes(char *line)
{
	t_map	*node;

	node = malloc(sizeof(t_map));
	if (!node)
	{
		perror("Error");
		exit(1);
	}
	node->line = line;
	node->next = NULL;
	return (node);
}

t_map	*get_lines_to_list(char *map_file, int height)
{
	t_map	*map_cpy;
	t_map	*current;
	t_map	*new_node;
	int		fd;
	char	*line;

	fd = open(map_file, O_RDONLY);
	map_cpy = NULL;
	while (height-- > 0)
	{
		line = get_next_line(fd);
		if (!line)
			return (close(fd), free_map(map_cpy), NULL);
		new_node = create_nodes(line);
		if (!map_cpy)
			map_cpy = new_node;
		else
			current->next = new_node;
		current = new_node;
	}
	close(fd);
	return (map_cpy);
}

t_map	*cpy_map_to_list(char *map_file)
{
	t_map	*map_cpy;

	map_cpy = ft_calloc(sizeof(t_map), 1);
	if (!map_cpy)
	{
		perror("Error");
		return (NULL);
		exit(1);
	}
	map_cpy->height = get_height(map_file);
	if (map_cpy->height == -1)
		return (free_map(map_cpy), NULL);
	map_cpy->width = get_width(map_file);
	if (map_cpy->width == -1)
		return (free_map(map_cpy), NULL);
	map_cpy->line = NULL;
	map_cpy->next = get_lines_to_list(map_file, map_cpy->height);
	if (!map_cpy->next)
	{
		free(map_cpy);
		return (NULL);
	}
	return (map_cpy);
}
