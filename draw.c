/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:11:08 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/05/30 17:11:08 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void		ft_string(void *mlx_ptr, void *win_ptr, t_norm1 norm)
{
	t_norm2		tn;

	tn.i = 0;
	tn.deltax = norm.x2 - norm.x1;
	tn.deltay = norm.y2 - norm.y1;
	if (fabs(tn.deltax) >= fabs(tn.deltay))
	{
		tn.k = tn.deltay / tn.deltax;
		ft_pixel(mlx_ptr, win_ptr, norm, tn);
	}
	else
	{
		tn.k = tn.deltax / tn.deltay;
		ft_pixelhelp(mlx_ptr, win_ptr, norm, tn);
	}
}

void		ft_value_norm(t_norm1 *norm, int ynew, int xnew, int z)
{
	norm->y2 = ynew;
	norm->x2 = xnew;
	norm->z2 = z;
}

void		ft_postroenie_x(t_crdt **krd)
{
	t_norm1				norm;
	t_crdt				*new;

	norm.xwin = (*krd)->winx;
	norm.ywin = (*krd)->winy;
	norm.win_ptr = (*krd)->win_ptr;
	norm.mlx_ptr = (*krd)->mlx_ptr;
	norm.zmin = (*krd)->zmin;
	norm.zmax = (*krd)->zmax;
	while ((*krd)->next != NULL)
	{
		norm.y1 = (*krd)->ynew;
		norm.x1 = (*krd)->xnew;
		norm.z1 = (*krd)->z;
		norm.clr = (*krd)->color;
		norm.row = (*krd)->row;
		new = (*krd)->next;
		if (norm.row == new->row)
		{
			ft_value_norm(&norm, new->ynew, new->xnew, new->z);
			norm.clr2 = new->color;
			ft_string(norm.mlx_ptr, norm.win_ptr, norm);
		}
		krd = &(*krd)->next;
	}
}

void		ft_postroenie_y(t_crdt **krd)
{
	t_norm1				norm;
	t_crdt				*new;

	norm.xwin = (*krd)->winx;
	norm.ywin = (*krd)->winy;
	norm.win_ptr = (*krd)->win_ptr;
	norm.mlx_ptr = (*krd)->mlx_ptr;
	norm.zmin = (*krd)->zmin;
	norm.zmax = (*krd)->zmax;
	while ((*krd)->next != NULL)
	{
		norm.y1 = (*krd)->ynew;
		norm.x1 = (*krd)->xnew;
		norm.z1 = (*krd)->z;
		norm.column = (*krd)->column;
		norm.clr = (*krd)->color;
		new = (*krd)->next;
		if (norm.column == new->column)
		{
			ft_value_norm(&norm, new->ynew, new->xnew, new->z);
			norm.clr2 = new->color;
			ft_string(norm.mlx_ptr, norm.win_ptr, norm);
		}
		krd = &(*krd)->next;
	}
}
