/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/17 17:15:35 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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


int	get_width(char *map_file)
{
	t_map	map;
	char	*abs;
	int		fd;

	map.width = 0;
	fd = open (map_file, O_RDONLY);
	abs = get_next_line(fd);
	while (*abs)
	{
		abs++;
		map.width++;
	}
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

void launch_fdf(char *map_file)
{
	//t_data	data;
    t_map map;

    //map.height = 0;
    //map.width = 0;
    map.height = get_height(map_file);
	dprintf(STDOUT_FILENO, "height is : %d\n", map.height);
  	map.width = get_width(map_file);
	dprintf(STDOUT_FILENO, "width is : %d\n", map.width);
    //lines_count = ft_split(abs, '\n');
    //if (!lines_count)
       // exit(EXIT_FAILURE);
    /*while (lines_count[map.height])
    {
        map.height++;
    }*/
    /*if (map.height > 0)
    {
        splitted_abs = ft_split(lines_count[0], ' ');
        while (splitted_abs[map.width])
            map.width++;
    }*/
	//dprintf(STDOUT_FILENO, "%d\n", map.height);
  //  free_split(lines_count);
	/*data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	generate_points(data.mlx_ptr, data.win_ptr, splitted_abs, map.width, map.height);
	mlx_key_hook(data.win_ptr, key_hook, NULL);
	mlx_loop(data.mlx_ptr);*/
}

/*void	launch_fdf(char *map_file)
{
	t_map	map;
	char	*abs;
	char	**splitted_abs;

	map.height = 0;
	map.width = 0;
	abs = read_map(map_file);
	if (!abs)
		exit(EXIT_FAILURE);
	splitted_abs = ft_split(abs, ' ');
	//free(abs);
	if (!splitted_abs)
		exit(EXIT_FAILURE);
	//generate_lines();
	while (abs[map.height])
	{
		if (map.width == 0)
		{
			while (splitted_abs[map.width])
				map.width++;
		}
	//	free_split(splitted_abs);
		map.height++;
	}
//	free(abs);
	dprintf(STDOUT_FILENO, "%d\n", map.height);

		//free(points);
}*/
