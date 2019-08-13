/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:31:28 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/05/22 13:31:28 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int			keyex(int key, t_ptr *help)
{
	if (key == 84)
	{
		(*help->el1)->z_vr = (*help->el1)->z_vr + 10;
		ft_drawmap(help);
	}
	if (key == 83)
	{
		(*help->el1)->z_vr = (*help->el1)->z_vr - 10;
		ft_drawmap(help);
	}
	if (key == 69)
	{
		(*help->el1)->proection = (*help->el1)->proection + 0.1;
		ft_drawmap(help);
	}
	if (key == 78)
	{
		(*help->el1)->proection = (*help->el1)->proection - 0.1;
		ft_drawmap(help);
	}
	return (0);
}

int			keyexhelp(int key, t_ptr *help)
{
	if (key == 18)
	{
		(*help->el1)->x_vr = 0;
		(*help->el1)->y_vr = 0;
		(*help->el1)->z_vr = 0;
		ft_drawmap(help);
	}
	if (key == 19)
	{
		mlx_clear_window((*help->el1)->mlx_ptr, (*help->el1)->win_ptr);
		(*help->el2)->zoom = (*help->el1)->zoom;
		(*help->el2)->proection = (*help->el1)->proection;
		(*help->el2)->x_vr = (*help->el1)->x_vr;
		(*help->el2)->y_vr = (*help->el1)->y_vr;
		(*help->el2)->z_vr = (*help->el1)->z_vr;
		proection_izo(*help->el1);
		proection_izohelp(*help->el2);
	}
	if (key == 53)
	{
		cleantcrdt(help->el1, help->el2);
		exit(0);
	}
	return (0);
}

int			finishhim(char *str)
{
	ft_putendl(str);
	return (1);
}

void		ft_zmiddle(t_mass elem, t_crdt **qwer, t_crdt **asdf)
{
	int y;
	int x;
	int zmin;
	int zmax;

	y = 0;
	zmin = elem.massive[y][y];
	zmax = elem.massive[y][y];
	while (y < elem.y)
	{
		x = 0;
		while (x <= elem.x)
		{
			if (elem.massive[y][x] < zmin)
				zmin = elem.massive[y][x];
			if (elem.massive[y][x] > zmax)
				zmax = elem.massive[y][x];
			x++;
		}
		y++;
	}
	(*qwer)->zmin = zmin;
	(*qwer)->zmax = zmax;
	(*asdf)->zmin = zmin;
	(*asdf)->zmax = zmax;
}

int			main(int argc, char **argv)
{
	t_crdt	*asdf;
	t_crdt	*qwer;
	t_ptr	help;
	t_mass	*elem;
	t_color *fdf1;

	if (argc != 2)
		return (finishhim("error: not enough arguments"));
	if ((elem = collect_coordinate(argv[1])) == NULL)
		return (finishhim("error: invalid file"));
	fdf1 = *(elem->clr);
	qwer = ft_fill_list_ox(&qwer, *elem, elem->clr);
	asdf = ft_fill_list_oy(&asdf, *elem, &fdf1);
	ft_zmiddle(*elem, &qwer, &asdf);
	cleanup(elem, 1, &fdf1);
	ft_fill_list_mlx(&qwer);
	help.el1 = &qwer;
	help.el2 = &asdf;
	mlx_hook(qwer->win_ptr, 2, 0, keyex, &help);
	mlx_hook(qwer->win_ptr, 3, 0, keyexhelp, &help);
	mlx_hook(qwer->win_ptr, 4, 0, hook_mousedown, &help);
	mlx_hook(qwer->win_ptr, 5, 0, hook_mouseup, &help);
	mlx_hook(qwer->win_ptr, 6, 0, hook_mousemove, &help);
	mlx_loop(qwer->mlx_ptr);
	return (0);
}
