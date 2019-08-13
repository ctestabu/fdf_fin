/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 17:02:07 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/06 19:12:47 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void		ft_lstaddpop(t_crdt **alst, t_crdt *new)
{
	t_crdt *node;

	node = *alst;
	if (node == NULL)
		*alst = new;
	else
	{
		while (node->next != NULL)
		{
			node = node->next;
		}
		node->next = new;
	}
}

t_crdt		*ft_lstnewcoor(int y, int x, double z, t_norm *norm)
{
	t_crdt	*element;

	if (!(element = (t_crdt *)malloc(sizeof(t_crdt))))
		return (NULL);
	else
	{
		element->y = y;
		element->x = x;
		element->z = z;
		element->color = 0;
		element->column = norm->column;
		element->row = norm->row;
	}
	element->next = NULL;
	return (element);
}

t_crdt		*ft_fill_list_ox(t_crdt **lst1, t_mass elem, t_color **clr)
{
	t_norm	n;
	t_crdt	*new;
	t_color *color;

	color = *clr;
	ft_fill_value_norm(&n);
	while (n.y <= elem.y)
	{
		n.x = 0;
		while (n.x <= elem.x)
		{
			ft_fill_value_norm1(&n);
			new = ft_lstnewcoor(n.y * n.yb - n.yb * elem.y / 2,
					n.x * n.xb - n.xb * elem.x / 2, elem.massive[n.y][n.x], &n);
			if (color != NULL && color->y == n.y && color->x == n.x)
			{
				new->color = color->clr;
				color = color->next;
			}
			ft_lstaddpop(lst1, new);
			n.x++;
		}
		n.y++;
	}
	return (*lst1);
}

t_crdt		*ft_fill_list_oy(t_crdt **lst2, t_mass elem, t_color **clr)
{
	t_norm	n;
	t_crdt	*new;
	t_color *color;

	color = *clr;
	n.x = 0;
	n.yb = 1;
	n.xb = 1;
	while (n.x <= elem.x)
	{
		n.y = 0;
		while (n.y <= elem.y)
		{
			n.column = n.x;
			n.row = n.y;
			new = ft_lstnewcoor(n.y * n.yb - n.yb * elem.y / 2,
					n.x * n.xb - n.xb * elem.x / 2, elem.massive[n.y][n.x], &n);
			if (color != NULL)
				new->color = colorcheck(color, n.y, n.x);
			ft_lstaddpop(lst2, new);
			n.y++;
		}
		n.x++;
	}
	return (*lst2);
}

void		ft_fill_list_mlx(t_crdt **lst)
{
	(*lst)->mlx_ptr = mlx_init();
	(*lst)->win_ptr = mlx_new_window((*lst)->mlx_ptr, 1920, 1080, "EVVRVIVI");
	(*lst)->x_vr = 0;
	(*lst)->y_vr = 0;
	(*lst)->z_vr = 0;
	(*lst)->zoom = 1;
	(*lst)->proection = 1;
	(*lst)->winx = 1920 / 2;
	(*lst)->winy = 1080 / 2;
	(*lst)->test = 0;
}
