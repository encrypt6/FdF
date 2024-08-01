/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:23:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/01 14:08:40 by elsikira         ###   ########.fr       */
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
		return (NULL);
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
	int		i;

	fd = open(map_file, O_RDONLY);
	map_cpy = NULL;
	i = 0;
	while (i < height)
	{
		line = get_next_line(fd);
		new_node = create_nodes(line);
		if (!new_node)
			return (close(fd), NULL);
		if (!map_cpy)
			map_cpy = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	close(fd);
	return (map_cpy);
}

t_map	*cpy_map_to_list(char *map_file)
{
	t_map	*map_cpy;

	map_cpy = malloc(sizeof(t_map));
	if (!map_cpy)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
	map_cpy->height = get_height(map_file);
	map_cpy->width = get_width(map_file);
	map_cpy->line = NULL;
	map_cpy->next = get_lines_to_list(map_file, map_cpy->height);
	if (!map_cpy->next)
	{
		free(map_cpy);
		return (NULL);
	}
	return (map_cpy);
}
