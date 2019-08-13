/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 15:37:56 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/05/22 15:37:56 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include "fdf.h"

void		ft_lstaddpopclr(t_color **alst, t_color *new)
{
	t_color *node;

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

t_color		*ft_lstnewcoorclr(int y, int x, int clr)
{
	t_color	*element;

	if (!(element = (t_color *)malloc(sizeof(t_color))))
		return (NULL);
	else
	{
		element->y = y;
		element->x = x;
		element->clr = clr;
	}
	element->next = NULL;
	return (element);
}

int			*massive_collect(char *line, t_mass *elems, t_color **clr, int y)
{
	int		*elements;
	char	**str;
	int		i;

	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i] != NULL)
		i++;
	if (elems->x == -1)
		elems->x = i - 1;
	else if (elems->x != i - 1)
		return (0);
	elements = (int*)malloc(sizeof(int) * i);
	i = 0;
	while (str[i] != NULL)
	{
		if (ft_strisdigit(str[i], clr, i, y) == 0)
			return (0);
		elements[i] = ft_atoi(str[i]);
		free(str[i]);
		i++;
	}
	free(str);
	return (elements);
}

int			checkfd(char *filename, t_mass *elems)
{
	int		i;
	char	*line;

	i = 0;
	if ((elems->file = open(filename, O_RDONLY)) < 0)
		return (-1);
	while (get_next_line(elems->file, &line))
	{
		if (ft_strlen(line) == 0)
			return (-1);
		i++;
		ft_strdel(&line);
	}
	close(elems->file);
	elems->y = i - 1;
	return (i + 1);
}

t_mass		*collect_coordinate(char *filename)
{
	int		**massive;
	t_mass	*elems;
	t_color *clr;

	elems = (t_mass*)malloc(sizeof(t_mass) * 1);
	elems->x = -1;
	if ((elems->i = checkfd(filename, elems)) == -1)
		return (cleanup(elems, -1, &clr));
	massive = (int**)malloc(sizeof(int*) * elems->i);
	massive[elems->i] = NULL;
	elems->i = 0;
	elems->file = open(filename, O_RDONLY);
	while (get_next_line(elems->file, &elems->line))
	{
		massive[elems->i] = massive_collect(elems->line, elems, &clr, elems->i);
		if (massive[elems->i] == 0)
		{
			elems->massive = massive;
			return (cleanup(elems, 1, &clr));
		}
		ft_strdel(&elems->line);
		elems->i++;
	}
	last_norminette(elems, massive, clr);
	return (elems);
}
