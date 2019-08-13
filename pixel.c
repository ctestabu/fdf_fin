/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 16:47:01 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/14 16:47:01 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int			get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

double		percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			get_color(int start, int end, double percentage)
{
	int red;
	int green;
	int blue;

	red = get_light((start >> 16) & 0xFF, (end >> 16) & 0xFF, percentage);
	green = get_light((start >> 8) & 0xFF, (end >> 8) & 0xFF, percentage);
	blue = get_light(start & 0xFF, end & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}

void		ft_pixel(void *mlx_ptr, void *win_ptr, t_norm1 norm, t_norm2 tn)
{
	t_rgb		rgb;
	double		percentage;

	percentage = percent(norm.zmin, norm.zmax, norm.z1);
	rgb.start = get_color(0xFFFFFF, 0xFF0000, percentage);
	if (norm.clr != 0)
		rgb.start = norm.clr;
	percentage = percent(norm.zmin, norm.zmax, norm.z2);
	rgb.end = get_color(0xFFFFFF, 0xFF0000, percentage);
	if (norm.clr2 != 0)
		rgb.end = norm.clr2;
	while (tn.deltax > 0 ? tn.i <= tn.deltax : tn.i >= tn.deltax)
	{
		percentage = percent(0, (int)fabsf(tn.deltax), abs(tn.i));
		rgb.current = get_color(rgb.start, rgb.end, percentage);
		mlx_pixel_put(mlx_ptr, win_ptr, norm.xwin + tn.i + norm.x1,
				norm.ywin + tn.i * tn.k + norm.y1, rgb.current);
		tn.deltax > 0 ? ++tn.i : --tn.i;
	}
}

void		ft_pixelhelp(void *mlx_ptr, void *win_ptr, t_norm1 norm, t_norm2 tn)
{
	t_rgb		rgb;
	double		percentage;

	percentage = percent(norm.zmin, norm.zmax, norm.z1);
	rgb.start = get_color(0xFFFFFF, 0xFF0000, percentage);
	if (norm.clr != 0)
		rgb.start = norm.clr;
	percentage = percent(norm.zmin, norm.zmax, norm.z2);
	rgb.end = get_color(0xFFFFFF, 0xFF0000, percentage);
	if (norm.clr2 != 0)
		rgb.end = norm.clr2;
	while (tn.deltay > 0 ? tn.i <= tn.deltay : tn.i >= tn.deltay)
	{
		percentage = percent(0, (int)fabsf(tn.deltay), abs(tn.i));
		rgb.current = get_color(rgb.start, rgb.end, percentage);
		mlx_pixel_put(mlx_ptr, win_ptr, norm.xwin + tn.i * tn.k + norm.x1,
				norm.ywin + tn.i + norm.y1, rgb.current);
		tn.deltay > 0 ? ++tn.i : --tn.i;
	}
}
