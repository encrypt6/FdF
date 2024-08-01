/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin_wu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/07/25 19:03:09 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float fpart(float x)
{
	return(x - floorf(x));
}

float rfpart(float x)
{
	return(1.0 - fpart(x));
}

void plot(t_data data, int x, int y, float brightness)
{
	int color;
	color = (int)(brightness * 255) << 16 | (int)(brightness * 255) << 8 | (int)(brightness * 255);
	mlx_pixel_put(data.mlx_ptr, data.win_ptr, x, y, color);
}

void ft_xiaolin_wu(t_point p0, t_point p1, t_data data)
{
	//put this in xiaolin_struct
	int	steep;
	float	dx;
	float	dy;
	float	gradient;
	float	xend;
	float	yend;
	float	xgap;
	int	xpxl1;
	int	ypxl1;
	float	intery;
	int	xpxl2;
	int	ypxl2;
	int	x;

	//little function
	steep = abs(p1.y - p0.y) > abs(p1.x - p0.x);
	if (steep)
	{
		ft_swap(&p0.x, &p0.y);
		ft_swap(&p1.x, &p1.y);
	}
	if (p0.x > p1.x)
	{
		ft_swap(&p0.x, &p1.x);
		ft_swap(&p0.y, &p1.y);
	}
	//little function
	dx = (float)p1.x - (float)p0.x;
	dy = (float)p1.y - (float)p0.y;
	gradient = dy / dx;
	xend = roundf(p0.x);
	yend = p0.y + gradient * (xend - p0.x);
	xgap = rfpart(p0.x + 0.5);
	xpxl1 = xend;
	ypxl1 = (int)yend;
	if(steep)
	{
		plot(data, ypxl1, xpxl1, rfpart(yend) * xgap);
		plot(data, ypxl1 + 1, xpxl1, fpart(yend) * xgap);
	}
	else
	{
		plot(data, xpxl1, ypxl1, rfpart(yend) * xgap);
		plot(data, xpxl1, ypxl1 + 1, fpart(yend) * xgap);
	}
	//little function
	intery = yend + gradient;
	xend = roundf(p1.x);
	yend = p1.y + gradient * (xend - p1.x);
	xgap = fpart(p1.x + 0.5);
	xpxl2 = xend;
	ypxl2 = (int)yend;
	if(steep)
	{
		plot(data, ypxl2, xpxl2, rfpart(yend) * xgap);
		plot(data, ypxl2 + 1, xpxl2, fpart(yend) * xgap);
	}
	else
	{
		plot(data, xpxl2, ypxl2, rfpart(yend) * xgap);
		plot(data, xpxl2, ypxl2 + 1, fpart(yend) * xgap);
	}
	//little function
	x = xpxl1 + 1;
	if(steep)
	{
		while(x < xpxl2)
		{
			plot(data, (int)intery, x, rfpart(intery));
			plot(data, (int)intery + 1, x, fpart(intery));
			intery += gradient;
			x++;
		}
	}
	else
	{
		while(x < xpxl2)
		{
			plot(data, x, (int)intery, rfpart(intery));
			plot(data, x, (int)intery + 1, fpart(intery));
			intery += gradient;
			x++;
		}
	}
}
