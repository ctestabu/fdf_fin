/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:37:26 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/06 21:37:26 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void	ft_helpiter3line(t_crdt *crdt, t_norm3 nrm, int i)
{
	if (i == 1)
	{
		crdt->ynew =
				nrm.y * cos(M_PI / 720 * nrm.a)
						+ nrm.z * sin(M_PI / 720 * nrm.a);
		crdt->znew = -1 * nrm.y * sin(M_PI / 720 * nrm.a)
				+ nrm.z * cos(M_PI / 720 * nrm.a);
	}
	if (i == 2)
	{
		crdt->xnew = nrm.x * cos(M_PI / 720 * nrm.b)
				+ nrm.z * sin(M_PI / 720 * nrm.b);
		crdt->znew = -1 * nrm.x * sin(M_PI / 720 * nrm.b)
				+ nrm.z * cos(M_PI / 720 * nrm.b);
	}
	if (i == 3)
	{
		crdt->xnew = nrm.x * cos(M_PI / 720 * nrm.g)
				+ nrm.y * sin(M_PI / 720 * nrm.g);
		crdt->ynew = -1 * nrm.x * sin(M_PI / 720 * nrm.g)
				+ nrm.y * cos(M_PI / 720 * nrm.g);
	}
}

void	ft_helpiter3line2(t_crdt *crdt, t_norm3 nrm)
{
	crdt->ynew =
			nrm.y * cos(M_PI / 720 * nrm.a)
					+ nrm.z * sin(M_PI / 720 * nrm.a);
	crdt->znew = -1 * nrm.y * sin(M_PI / 720 * nrm.a)
			+ nrm.z * cos(M_PI / 720 * nrm.a);
	nrm.y = crdt->ynew;
	nrm.z = crdt->znew;
	crdt->xnew = nrm.x * cos(M_PI / 720 * nrm.b)
			+ nrm.z * sin(M_PI / 720 * nrm.b);
	crdt->znew = -1 * nrm.x * sin(M_PI / 720 * nrm.b)
			+ nrm.z * cos(M_PI / 720 * nrm.b);
	nrm.x = crdt->xnew;
	nrm.z = crdt->znew;
	crdt->xnew = nrm.x * cos(M_PI / 720 * nrm.g)
			+ nrm.y * sin(M_PI / 720 * nrm.g);
	crdt->ynew = -1 * nrm.x * sin(M_PI / 720 * nrm.g)
			+ nrm.y * cos(M_PI / 720 * nrm.g);
}

void	ft_iter3line(t_crdt **crdt, int alpha, int beta, int gamma)
{
	t_norm3 nrm;

	nrm.a = alpha;
	nrm.b = beta;
	nrm.g = gamma;
	nrm.zoom = (*crdt)->zoom;
	nrm.proection = (*crdt)->proection;
	while ((*crdt))
	{
		nrm.x = (*crdt)->x * nrm.zoom;
		nrm.y = (*crdt)->y * nrm.zoom;
		nrm.z = (*crdt)->z * nrm.proection * nrm.zoom;
		if (alpha > 0 && beta == 0 && gamma == 0)
			ft_helpiter3line(*crdt, nrm, 1);
		if (beta > 0 && alpha == 0 && gamma == 0)
			ft_helpiter3line(*crdt, nrm, 2);
		if (gamma > 0 && alpha == 0 && beta == 0)
			ft_helpiter3line(*crdt, nrm, 3);
		else
			ft_helpiter3line2(*crdt, nrm);
		crdt = &(*crdt)->next;
	}
}

void	ft_drawmap(t_ptr *help)
{
	mlx_clear_window((*help->el1)->mlx_ptr, (*help->el1)->win_ptr);
	(*help->el2)->proection = (*help->el1)->proection;
	(*help->el2)->zoom = (*help->el1)->zoom;
	(*help->el2)->winx = (*help->el1)->winx;
	(*help->el2)->winy = (*help->el1)->winy;
	(*help->el2)->mlx_ptr = (*help->el1)->mlx_ptr;
	(*help->el2)->win_ptr = (*help->el1)->win_ptr;
	ft_iter3line(help->el1, (*help->el1)->x_vr, (*help->el1)->y_vr,
			(*help->el1)->z_vr);
	ft_iter3line(help->el2, (*help->el1)->x_vr, (*help->el1)->y_vr,
			(*help->el1)->z_vr);
	ft_postroenie_x(help->el1);
	ft_postroenie_y(help->el2);
}
