/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgeorgia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:34:02 by lgeorgia          #+#    #+#             */
/*   Updated: 2019/05/22 13:34:02 by lgeorgia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "mlx.h"
# include <math.h>
# include <stdio.h>

typedef	struct			s_rgb
{
	int					start;
	int					end;
	int					current;
}						t_rgb;

typedef	struct			s_norm3
{
	double				x;
	double				y;
	double				z;
	int					zoom;
	int					a;
	int					b;
	int					g;
	double				proection;
}						t_norm3;

typedef	struct			s_norm2
{
	float				k;
	float				deltax;
	float				deltay;
	int					i;
}						t_norm2;

typedef	struct			s_norm1
{
	int					x1;
	int					y1;
	int					x2;
	int					y2;
	int					z1;
	int					z2;
	int					zmin;
	int					zmax;
	int					ywin;
	int					xwin;
	int					column;
	int					row;
	void				*mlx_ptr;
	void				*win_ptr;
	int					clr;
	int					clr2;
}						t_norm1;

typedef	struct			s_norm
{
	int					yb;
	int					xb;
	int					column;
	int					row;
	int					x;
	int					y;

}						t_norm;

typedef	struct			s_color
{
	int					x;
	int					y;
	int					clr;
	struct s_color		*next;
}						t_color;

typedef	struct			s_mass
{
	int					i;
	int					**massive;
	int					y;
	int					x;
	int					file;
	char				*line;
	t_color				**clr;
}						t_mass;

typedef	struct			s_coordinate
{
	int					y;
	int					x;
	double				z;
	int					ynew;
	int					xnew;
	int					znew;
	int					height;
	int					column;
	int					row;
	struct s_coordinate	*next;
	int					x_vr;
	int					y_vr;
	int					z_vr;
	double				proection;
	double				zoom;
	void				*mlx_ptr;
	void				*win_ptr;
	int					winx;
	int					winy;
	int					zmin;
	int					zmax;
	int					xmouse;
	int					ymouse;
	int					lastx;
	int					lasty;
	int					mx;
	int					my;
	int					test;
	int					file;
	int					color;
}						t_crdt;

typedef	struct			s_ptr
{
	t_crdt				**el1;
	t_crdt				**el2;
}						t_ptr;

t_mass					*collect_coordinate(char *filename);
void					ft_iterlst(t_crdt *crdt);
void					ft_lstaddpop(t_crdt **alst, t_crdt *new);
t_crdt					*ft_lstnewcoor(int y, int x, double z, t_norm *norm);
t_crdt					*ft_fill_list_ox(t_crdt **lst1, t_mass elem,
		t_color **clr);
t_crdt					*ft_fill_list_oy(t_crdt **lst2, t_mass elem,
		t_color **clr);
void					ft_string(void *mlx_ptr, void *win_ptr, t_norm1 norm);
void					ft_postroenie_x(t_crdt **krd);
void					ft_postroenie_y(t_crdt **krd);
void					ft_fill_list_mlx(t_crdt **lst);
void					ft_helpiter3line(t_crdt *crdt, t_norm3 nrm, int i);
void					ft_helpiter3line2(t_crdt *crdt, t_norm3 nrm);
void					ft_iter3line(t_crdt **crdt, int alpha, int beta,
		int gamma);
void					ft_drawmap(t_ptr *help);
int						cleantcrdt(t_crdt **crdt1, t_crdt **crdt2);
t_mass					*cleanup(t_mass *clean1, int i, t_color **clean);
int						hook_mousedown(int button, int x, int y, t_ptr *help);
int						hook_mouseup(int button, int x, int y, t_ptr *help);
int						hook_mousemove(int x, int y, t_ptr *help);
int						checkfd(char *filename, t_mass *elems);
void					proection_izohelp(t_crdt *ox);
void					proection_izo(t_crdt *ox);
void					ft_pixelhelp(void *mlx_ptr, void *win_ptr, t_norm1 norm,
		t_norm2 tn);
void					ft_pixel(void *mlx_ptr, void *win_ptr, t_norm1 norm,
		t_norm2 tn);
void					ft_fill_value_norm(t_norm *n);
void					ft_fill_value_norm1(t_norm *n);
int						colorcheck(t_color *clrd, int y, int x);
int						ft_strisdigit(char *str, t_color **clr, int x, int y);
t_color					*ft_lstnewcoorclr(int y, int x, int clr);
void					ft_lstaddpopclr(t_color **alst, t_color *new);
void					last_norminette(t_mass *elems, int **massive,
		t_color *clr);

#endif
