/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin_wu_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <elsikira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 22:16:56 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/20 17:23:32 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/* 
	fpart returns the fractional part of x. Ex : x = 15.06,
	fpart(x) 15.06 - 15 = 0.06
	rfpart returns 1 - fpart(x). Ex : rfpart(x) = 1 - 0.06 = 0.94
	plot handles the brightness with RGB components from white to grey,
	to black based on the position of the pixels 
*/
float	fpart(float x)
{
	return (x - floorf(x));
}

float	rfpart(float x)
{
	return (1.0 - fpart(x));
}

void	plot(t_img *img, int x, int y, float brightness)
{
	int	color;
	int	offset;

	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	color = (int)(brightness * 255) << 16
		| (int)(brightness * 255) << 8
		| (int)(brightness * 255);
	offset = (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)(img->data + offset) = color;
}
