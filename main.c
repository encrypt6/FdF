/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 18:34:45 by elsikira          #+#    #+#             */
/*   Updated: 2024/02/27 17:36:07 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"

// int	main(int argc, char *argv[])
// {
// 	t_img	image;
// 	t_win	fdf;
// 	t_cam	camera;
// 

#include "../includes/fdf.h"

int	main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "My first window!");
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
