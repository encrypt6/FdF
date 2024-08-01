/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 11:56:11 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/01 14:37:18 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H 

# define WINDOW_WIDTH 1080
# define WINDOW_HEIGHT 650
# define ESC_KEY 65307
# define SCALE_X 4
# define SCALE_Y 4

# include "libft/libft.h"
# include <math.h>
# include "minilibx-linux/mlx_int.h"
# include "minilibx-linux/mlx.h"

typedef struct	s_xiao
{
	int		steep;
	float	dx;
	float	dy;
	float	gradient;
	float	xend;
	float	yend;
	float	xgap;
	int		xpxl1;
	int		ypxl1;
	float	intery;
	int		xpxl2;
	int		ypxl2;
	int		x;
}t_xiao;

typedef struct	s_point
{
	int	x;
	int	y;
	int	z;
}t_point;

typedef struct	s_map
{
	int				height;
	int				width;
	struct s_map	*head;
	struct s_map	*next;
	char			*line;
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

t_map	*cpy_map_to_list(char *map_file);

int	get_width(char *map_file);

int	get_height(char *map_file);

void	fill_matrix(t_map *map_cpy);

void	free_map(t_map *map);

void	draw(t_map *map_cpy, t_data data);

//view.c
t_point	isometric(t_point point, int map_width, int map_height);

void ft_xiaolin_wu(t_point p0, t_point p1, t_data data);

#endif
