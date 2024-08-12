/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xiaolin_wu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elsikira <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 16:08:47 by elsikira          #+#    #+#             */
/*   Updated: 2024/08/12 22:18:46 by elsikira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	between_points(t_xiao *xiao, t_img *img)
{
	xiao->x = xiao->xpxl1 + 1;
	if (xiao->steep)
	{
		while (xiao->x < xiao->xpxl2)
		{
			plot(img, (int)xiao->intery, xiao->x, rfpart(xiao->intery));
			plot(img, (int)xiao->intery + 1, xiao->x, fpart(xiao->intery));
			xiao->intery += xiao->gradient;
			xiao->x++;
		}
	}
	else
	{
		while (xiao->x < xiao->xpxl2)
		{
			plot(img, xiao->x, (int)xiao->intery, rfpart(xiao->intery));
			plot(img, xiao->x, (int)xiao->intery + 1, fpart(xiao->intery));
			xiao->intery += xiao->gradient;
			xiao->x++;
		}
	}
}

void	second_point(t_point *p1, t_xiao *xiao, t_img *img)
{
	xiao->intery = xiao->yend + xiao->gradient;
	xiao->xend = roundf(p1->x);
	xiao->yend = p1->y + xiao->gradient * (xiao->xend - p1->x);
	xiao->xgap = fpart(p1->x + 0.5);
	xiao->xpxl2 = xiao->xend;
	xiao->ypxl2 = (int)xiao->yend;
	if (xiao->steep)
	{
		plot(img, xiao->ypxl2, xiao->xpxl2, rfpart(xiao->yend) * xiao->xgap);
		plot(img, xiao->ypxl2 + 1, xiao->xpxl2, fpart(xiao->yend) * xiao->xgap);
	}
	else
	{
		plot(img, xiao->xpxl2, xiao->ypxl2, rfpart(xiao->yend) * xiao->xgap);
		plot(img, xiao->xpxl2, xiao->ypxl2 + 1, fpart(xiao->yend) * xiao->xgap);
	}
}

void	first_point(t_point *p0, t_point *p1, t_xiao *xiao, t_img *img)
{
	xiao->dx = (float)p1->x - (float)p0->x;
	xiao->dy = (float)p1->y - (float)p0->y;
	xiao->gradient = xiao->dy / xiao->dx;
	xiao->xend = roundf(p0->x);
	xiao->yend = p0->y + xiao->gradient * (xiao->xend - p0->x);
	xiao->xgap = rfpart(p0->x + 0.5);
	xiao->xpxl1 = xiao->xend;
	xiao->ypxl1 = (int)xiao->yend;
	if (xiao->steep)
	{
		plot(img, xiao->ypxl1, xiao->xpxl1, rfpart(xiao->yend) * xiao->xgap);
		plot(img, xiao->ypxl1 + 1, xiao->xpxl1, fpart(xiao->yend) * xiao->xgap);
	}
	else
	{
		plot(img, xiao->xpxl1, xiao->ypxl1, rfpart(xiao->yend) * xiao->xgap);
		plot(img, xiao->xpxl1, xiao->ypxl1 + 1, fpart(xiao->yend) * xiao->xgap);
	}
}

void	steepness(t_point *p0, t_point *p1, t_xiao *xiao)
{
	xiao->steep = abs(p1->y - p0->y) > abs(p1->x - p0->x);
	if (xiao->steep)
	{
		ft_swap(&p0->x, &p0->y);
		ft_swap(&p1->x, &p1->y);
	}
	if (p0->x > p1->x)
	{
		ft_swap(&p0->x, &p1->x);
		ft_swap(&p0->y, &p1->y);
	}
}

void	ft_xiaolin_wu(t_point p0, t_point p1, t_img *img)
{
	t_xiao	xiao;

	steepness(&p0, &p1, &xiao);
	first_point(&p0, &p1, &xiao, img);
	second_point(&p1, &xiao, img);
	between_points(&xiao, img);
}
