/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:14:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/10 18:14:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int		hook_mousedown(int button, int x, int y, t_ptr *help)
{
	(void)x;
	if (y < 0)
		return (0);
	if (button == 1)
		(*help->el1)->test = (*help->el1)->test + 1;
	if (button == 2)
		(*help->el1)->test = (*help->el1)->test + 2;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_ptr *help)
{
	(void)x;
	(void)y;
	if (button == 1)
		(*help->el1)->test = (*help->el1)->test - 1;
	if (button == 2)
		(*help->el1)->test = (*help->el1)->test - 2;
	return (0);
}

int		hook_mousemove(int x, int y, t_ptr *help)
{
	(*help->el1)->lastx = (*help->el1)->mx;
	(*help->el1)->lasty = (*help->el1)->my;
	(*help->el1)->mx = x;
	(*help->el1)->my = y;
	if ((*help->el1)->test == 3)
	{
		(*help->el1)->winx = (*help->el1)->winx + (x - (*help->el1)->lastx);
		(*help->el1)->winy = (*help->el1)->winy + (y - (*help->el1)->lasty);
	}
	else if ((*help->el1)->test == 1)
	{
		(*help->el1)->x_vr = (*help->el1)->x_vr + ((*help->el1)->lasty - y);
		(*help->el1)->y_vr = (*help->el1)->y_vr - ((*help->el1)->lastx - x);
	}
	else if ((*help->el1)->test == 2)
	{
		(*help->el1)->zoom = (*help->el1)->zoom +
				((*help->el1)->lasty - y) / 10.0f;
		if ((*help->el1)->zoom < 1)
			(*help->el1)->zoom = 1;
	}
	if ((*help->el1)->test > 0)
		ft_drawmap(help);
	return (0);
}
