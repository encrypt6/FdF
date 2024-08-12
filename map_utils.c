/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 19:54:48 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 16:33:55 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

//	initialize_buffer(buffer, BUFFER_SIZE);
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
