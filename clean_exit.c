/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:38:25 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 20:06:22 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_data(t_data *data)
{
	get_next_line(-42);
	if (data)
	{
		if (data->mlx_ptr)
		{
			if (data->win_ptr)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		free(data);
	}
	exit(0);
}

void	clean_exit(t_data *data)
{
	if (data && data->mlx_ptr)
		mlx_loop_end(data->mlx_ptr);
	free_data(data);
}

int	close_window(t_data *data)
{
	clean_exit(data);
	return (0);
}

int	esc_exit(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		clean_exit(data);
	return (0);
}
