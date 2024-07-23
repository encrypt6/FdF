/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:54:48 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/23 17:04:55 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lines	get_lines(char *map_file, int height)
{
	t_lines	lines;
	int		fd;
	int		i;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (i < height + 1)
	{
		lines.line = get_next_line(fd);
		dprintf(STDOUT_FILENO, "%s", lines.line);
		free(lines.line);
		i++;
	}
	close (fd);
	return (lines);
}

int	get_width(char *map_file)
{
	t_map	map;
	char	*abs;
	char	**splitted_abs;
	int		fd;

	map.width = 0;
	fd = open(map_file, O_RDONLY);
	abs = get_first_line(fd);
	splitted_abs = ft_split(abs, ' ');
	free(abs);
	if (map.width == 0)
	{
		while (splitted_abs[map.width])
			map.width++;
	}
	free_split(splitted_abs);
	close(fd);
	return (map.width);
}

int	get_height(char *map_file)
{
	t_map	map;
	int		fd;
	char	*abs;
	
	map.height = 0;
	fd = open(map_file, O_RDONLY);
	while (1)
	{
		abs = get_next_line(fd);
		if (abs == NULL)
			break ;
		map.height++;
		free (abs);
		abs = NULL;
	}	
	close(fd);
	return(map.height);
}

t_map	*cpy_map_to_struct(char *map_file)
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
	map_cpy->lines = get_lines(map_file, map_cpy->height);
	return(map_cpy);
}
