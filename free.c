/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 18:11:58 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/10 18:11:58 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

int		cleantcrdt(t_crdt **crdt1, t_crdt **crdt2)
{
	t_crdt *next;

	if (crdt1 && *crdt1)
	{
		while (*crdt1)
		{
			next = (*crdt1)->next;
			ft_memdel((void **)crdt1);
			*crdt1 = next;
		}
		ft_memdel((void **)crdt1);
	}
	if (crdt2 && *crdt2)
	{
		while (*crdt1)
		{
			next = (*crdt2)->next;
			ft_memdel((void **)crdt2);
			*crdt2 = next;
		}
		ft_memdel((void **)crdt2);
	}
	return (0);
}

void	clean_color(t_color **clean)
{
	t_color *next;

	if (clean && *clean)
	{
		while (*clean)
		{
			next = (*clean)->next;
			ft_memdel((void**)clean);
			*clean = next;
		}
		ft_memdel((void **)clean);
	}
}

t_mass	*cleanup(t_mass *clean1, int i, t_color **clean)
{
	int count;

	count = 0;
	if (i == -1)
	{
		ft_memdel((void **)&clean1);
		return (NULL);
	}
	clean_color(clean);
	while (count < clean1->y)
	{
		ft_memdel((void **)&clean1->massive[count]);
		count++;
	}
	ft_memdel((void **)&clean1);
	return (NULL);
}

void	proection_izo(t_crdt *ox)
{
	t_crdt	*ad;
	double	zoom;
	double	izo;

	zoom = ox->zoom;
	ad = ox;
	izo = ox->proection;
	ad->x_vr = ox->x_vr;
	ad->y_vr = ox->y_vr;
	ad->z_vr = ox->z_vr;
	while (ox)
	{
		ox->znew = ox->z * zoom * izo;
		ox->xnew = ox->x * zoom + (sin(M_PI / 180) * 60) * (ox->znew);
		ox->ynew = ox->y * zoom + (sin(M_PI / 180) * 30) * (ox->znew);
		ox->xnew = ox->xnew * cos(M_PI / 720 * ad->y_vr)
				+ ox->znew * sin(M_PI / 720 * ad->y_vr);
		ox->znew = -1 * ox->xnew * sin(M_PI / 720 * ad->y_vr)
				+ ox->znew * cos(M_PI / 720 * ad->y_vr);
		ox = ox->next;
	}
	ft_postroenie_x(&ad);
}

void	proection_izohelp(t_crdt *ox)
{
	t_crdt	*ad;
	double	zoom;
	double	izo;

	zoom = ox->zoom;
	izo = ox->proection;
	ad = ox;
	ad->x_vr = ox->x_vr;
	ad->y_vr = ox->y_vr;
	ad->z_vr = ox->z_vr;
	while (ox)
	{
		ox->znew = ox->z * zoom * izo;
		ox->xnew = ox->x * zoom + (sin(M_PI / 180) * 60) * (ox->znew);
		ox->ynew = ox->y * zoom + (sin(M_PI / 180) * 30) * (ox->znew);
		ox->xnew = ox->xnew * cos(M_PI / 720 * ad->y_vr)
				+ ox->znew * sin(M_PI / 720 * ad->y_vr);
		ox->znew = -1 * ox->xnew * sin(M_PI / 720 * ad->y_vr)
				+ ox->znew * cos(M_PI / 720 * ad->y_vr);
		ox = ox->next;
	}
	ft_postroenie_y(&ad);
}
