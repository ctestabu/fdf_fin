/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:08:31 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/06/14 17:08:31 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void		ft_fill_value_norm(t_norm *n)
{
	n->y = 0;
	n->yb = 1;
	n->xb = 1;
}

void		ft_fill_value_norm1(t_norm *n)
{
	n->column = n->x;
	n->row = n->y;
}

int			colorcheck(t_color *clrd, int y, int x)
{
	t_color *clr;

	clr = clrd;
	while (clr)
	{
		if (clr->y == y && clr->x == x)
			return (clr->clr);
		clr = clr->next;
	}
	return (0);
}

int			ft_strisdigit(char *str, t_color **clr, int x, int y)
{
	int i;
	int color;

	i = 0;
	if (ft_strlen(str) == 0)
		return (0);
	while (str[i] != '\0')
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else if (str[i] == ',')
		{
			color = ft_atoi_base(&((char *)str)[i + 3], 16);
			ft_lstaddpopclr(clr, ft_lstnewcoorclr(y, x, color));
			return (1);
		}
		else
			return (0);
	}
	return (1);
}

void		last_norminette(t_mass *elems, int **massive, t_color *clr)
{
	elems->massive = massive;
	close(elems->file);
	elems->clr = &clr;
}
