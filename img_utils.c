/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 13:54:01 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/09 01:37:07 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clean_img(t_data *data, t_img *img)
{
	mlx_destroy_image(data->mlx_ptr, img->image);
	free(img);
}

t_img	*init_img(t_data *data, int win_width, int win_height)
{
	t_img	*img;
	int	endian;

	img = malloc(sizeof(t_img));
	if (!img)
	{
		perror("Error");
		exit(1);
	}
	img->image = mlx_new_image(data->mlx_ptr, win_width, win_height);
	img->data = mlx_get_data_addr(img->image, &img->bpp, &img->size_line, &endian);
	img->width = win_width;
	img->height = win_height;
	return (img);
}
