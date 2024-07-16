/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:25:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/16 18:37:02 by elsikira         ###   ########.fr       */
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

char	*read_map(char *map)
{
	int		fd;
	char	*abs;

	fd = open(map, O_RDONLY);
	abs = get_next_line(fd);
	close(fd);
	return(abs);
}

void	launch_fdf(char *map)
{
	//t_data	data;
	char	*abs;
	char	**splitted_abs;

	abs = read_map(map);
	if (!abs)
		exit(EXIT_FAILURE);
	splitted_abs = ft_split(abs, ' ');
	free(abs);
	if (!splitted_abs)
		exit(EXIT_FAILURE);
	dprintf(STDOUT_FILENO, "%s\n", splitted_abs[1]);
	free_split(splitted_abs);
	//generate_points();
	//generate_lines();
	/*data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My FdF");
	mlx_key_hook(data.win_ptr, key_hook, NULL);
	mlx_loop(data.mlx_ptr);
	free(points);*/
}
