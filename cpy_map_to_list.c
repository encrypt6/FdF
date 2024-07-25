/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_map_to_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:23:06 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 21:24:43 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*create_nodes(char *map_file, t_map *map_cpy)
{
	t_map	*node;
	t_map	*head;
	int		fd;

	fd = open(map_file, O_RDONLY);
	node = malloc(sizeof(t_map));
	if (!node)
	{
		perror("Error");
		close(fd);
		return (NULL);
	}
	node->line = get_next_line(fd);
	if (!node->line)
	{
		close(fd);
		return (NULL);
	}
	node->next = NULL;
	if (map_cpy == NULL)
		map_cpy = node;
	else
	{
		head = map_cpy;
		while (head->next != NULL)
			head = head->next;
		head->next = node;
	}
	close (fd);
	return (map_cpy);
}

t_map	*get_lines_to_list(char *map_file, int height)
{
	t_map	*map_cpy;
	t_map	*current;
	int		i;

	map_cpy = NULL;
	i = 0;
	while (i < height)
	{
		map_cpy = create_nodes(map_file, map_cpy);
		if (!map_cpy)
			return (NULL);
		current = map_cpy;
		while (current->next != NULL)
			current = current->next;
		if (current->line == NULL)
			break ;
		ft_dprintf(STDOUT_FILENO, "%s", current->line);
		free(current->line);
		current->line = NULL;
		i++;
	}
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
	map_cpy->next = get_lines_to_list(map_file, map_cpy->height);
	if (!map_cpy->next)
	{
		free(map_cpy);
		return (NULL);
	}
	return(map_cpy);
}
