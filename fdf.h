/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 21:05:17 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "config.h"
#include <bsd/string.h>

typedef struct			s_spec
{
	float	r;
	float	g;
	float	b;
}				t_spec;

typedef struct		s_dot
{
	float			x;
	float			y;
	float			z;
	int				row;
	int				color;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_colors
{
	char*		menu;
	char*		top;
	char*		mid;
	char*		bot;
}			t_colors;

typedef struct		s_param
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	t_dot		*dot;
	t_dot		*res;
	t_colors	*clr;
	int		dep[WINDOW_WIDTH][WINDOW_HEIGTH];
	unsigned char	*s;
	int		size;
}			t_param;

t_dot		*create_dot(int x, int y, int z, int c);
void		free_dot(t_dot **dot);
t_dot		*ft_reader(char *filename, t_colors *color);
void		add_dot(t_dot **dot, t_dot *new);
void		ft_cpy(t_dot **dest, t_dot *src);

void		ch_pixel_put(t_param *param, int x, int y, t_spec *c);
int		mouse_f(int buttom, int x, int y, void *param);
int		keyboard_f(int keycode, void *param);
int		hook_f(void *param);

void		get_color_inc(int n_pixels, unsigned int color1, unsigned int color2, t_spec *inc);
void		inc_st_color(t_spec *c, t_spec *inc);
void		get_spec(t_spec *s, unsigned int color);

void		tp_dot(t_param *param);
void		shift(t_dot *dot, int x, int y, int z);
void		zoom(t_dot *dot, float mult, int x, int y);
void		zoom_z(t_dot *dot, float mult, float multz);
void		net_dot(t_param *param);
void		net_dot_c(t_param *param);
void		new_net_dot(t_param *param);
void		sh_net_dot(t_param *param, int x, int y, int z);
void		zm_net_dot(t_param *param, float mult, int x, int y);
void		zx_net_dot(t_param *param, float mult);
void		draw_line_p(t_param *param, t_dot *dot1, t_dot *dot2);
void		draw_line_t(t_param *param, t_dot *dot1, t_dot *dot2);

void		clear_and_rest(t_param *param);
void		draw_box(t_param *param, t_dot *dot1, t_dot *dot4, int color);
void		draw_menu(t_param *param, int color);
void		rot_net_dot(t_param *param, float angle, char axis);
void		ox_rot(t_dot *dot, float a);
void		oy_rot(t_dot *dot, float a);
void		oz_rot(t_dot *dot, float a);
#endif
