/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 22:26:09 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "config.h"

typedef struct		s_spec
{
	float			r;
	float			g;
	float			b;
}					t_spec;

typedef struct		s_dot
{
	float			x;
	float			y;
	float			z;
	int				dep;
	int				row;
	int				color;
	struct s_dot	*next;
}					t_dot;

typedef struct		s_box
{
	t_dot			*dot1;
	t_dot			*dot2;
	t_dot			*dot3;
	t_dot			*dot4;
	int				ctr;
	struct s_box	*next;
}					t_box;

typedef struct		s_colors
{
	char*			menu;
	char*			top;
	char*			mid;
	char*			bot;
}					t_colors;

typedef struct		s_param
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	void			*menu_ptr;
	unsigned char	*s;
	int				size;
	float			mult;
	t_dot			*dot;
	t_dot			*res;
	t_box			*box;
	t_colors		*clr;
}					t_param;

t_dot				*create_dot(int x, int y, int z, int c);
t_box				*create_box(t_param *param);
void				free_box(t_box **box);
void				draw_box_new(t_param *param, t_box *box, char diag);
void				free_dot(t_dot **dot);
t_dot				*ft_reader(char *filename, t_colors *color);
void				add_dot(t_dot **dot, t_dot *new);
void				add_box(t_box **dot, t_box *new);
void				ft_cpy(t_dot **dest, t_dot *src);

void				ch_fill(t_param *param, int x, int y);
void				ch_pixel_put(t_param *param, int x, int y, t_spec *c);
int					mouse_f(int buttom, int x, int y, void *param);
int					keyboard_f(int keycode, void *param);
void				ft_colorize(t_dot *dot, t_colors *c);

void				get_color_inc(int n_pixels,
					unsigned int color1, unsigned int color2, t_spec *inc);
void				inc_st_color(t_spec *c, t_spec *inc);
void				get_spec(t_spec *s, unsigned int color);
int					get_inc_n_maxp(t_dot *dot1,
					t_dot *dot2, float *inc_x, float *inc_y);

void				tp_dot(t_param *param, char diag);
void				shift(t_dot *dot, int x, int y, int z);
void				zoom(t_dot *dot, float mult, int x, int y);
void				zoom_z(t_dot *dot, float mult, float multz);
void				net_dot(t_param *param);
void				net_dot_c(t_param *param);
void				net_box(t_param *param);
void				new_net_dot(t_param *param);
void				sh_net_dot(t_param *param, int x, int y, int z);
void				zm_net_dot(t_param *param, float mult, int x, int y);
void				zx_net_dot(t_param *param, float mult);
void				draw_line_p(t_param *param, t_dot *dot1, t_dot *dot2);
void				draw_line_t(t_param *param, t_dot *dot1, t_dot *dot2);
void				draw_line_d(t_param *param,
					t_dot *dot1, t_dot *dot2, int z);
void				draw_line_ch(t_param *param, t_dot *dot1, t_dot *dot2);
void				draw_box_n(t_param *param,
					t_dot *dot1, t_dot *dot2, t_dot *dot3);
void				ch_pixel_put_d(t_param *param, int x, int y, int z);
void				sort_box(t_box *box);
void				refresh_screen(t_param *param, int is_transp);

void				clear_and_rest(t_param *param);
void				draw_box(t_param *param,
					t_dot *dot1, t_dot *dot4, int color);
void				draw_menu(t_param *param, int color);
void				rot_net_dot(t_param *param, float angle, char axis);
void				ox_rot(t_dot *dot, float a);
void				oy_rot(t_dot *dot, float a);
void				oz_rot(t_dot *dot, float a);

void				free_and_exit(t_param *param);
void				error_file_msg(void);
void				usage_msg(void);

#endif
