/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:11 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/18 19:07:05 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H 

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720
# define ESC_KEY 65307

# include "libft/libft.h"
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}t_point;

typedef struct	s_map
{
	//t_point	**point;
	int	height;
	int width;
	int	point;
}t_map;

typedef struct	s_data
{
	t_map	*map;
	void	*mlx_ptr;
	void	*win_ptr;
}t_data;


int		main(int argc, char **argv);

void	check_all_errors(int argc, char **argv);

void	launch_fdf(char *argv);

int		key_hook(int key_code, void *param);

void	free_split(char **split);

t_map	*cpy_map_to_struct(char *map_file);





#endif
