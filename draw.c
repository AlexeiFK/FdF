/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:36:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 20:51:54 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "fdf.h"
#include "menu.h"
#include "libft.h"
#include "config.h"

static int	get_inc_n_maxp(t_dot *dot1, t_dot *dot2, float *inc_x, float *inc_y)
{
	float		dif_x;
	float		dif_y;

	*inc_x = 1;
	*inc_y = 1;
	if (dot1->x > dot2->x)
		*inc_x = -1;
	if (dot1->y > dot2->y)
		*inc_y = -1;
	dif_x = fabsf(dot2->x - dot1->x);
	dif_y = fabsf(dot2->y - dot1->y);
	if (dif_y > dif_x)
	{
		*inc_x = *inc_x * (dif_x / dif_y);
		return (fabsf(dif_y));
	}
	else
	{
		*inc_y = *inc_y * (dif_y / dif_x);
		return (fabsf(dif_x));
	}
}

void		get_color_inc(int n_pixels, unsigned int color1, unsigned int color2, t_spec *inc)
{
	float	inc_color;
	t_spec	s1;
	t_spec	s2;

	s1.r = color1 >> 16; //color1 / (65536);
	s1.g = (color1 << 16) >> 24;//(color1 / (256)) % (256);
	s1.b = (color1 << 24) >> 24;//color1 % (256);

	s2.r = color2 >> 16;//color2 / (65536);
	s2.g = (color2 << 16) >> 24;//(color2 / (256)) % (256);
	s2.b = (color2 << 24) >> 24;//color2 % (256);

	inc->r = ((s2.r - s1.r) / n_pixels); //
	inc->g = ((s2.g - s1.g) / n_pixels); //
	inc->b = ((s2.b - s1.b) / n_pixels);
}

void		inc_st_color(t_spec *c, t_spec *inc)
{
	c->r += inc->r;
	c->g += inc->g;
	c->b += inc->b;
}


void		get_spec(t_spec *s, unsigned int color)
{
	s->r = color >> 16; //color1 / (65536);
	s->g = (color << 16) >> 24;//(color1 / (256)) % (256);
	s->b = (color << 24) >> 24;//color1 % (256);
//	s->r = //color / (65536);
//	s->g = //(color / (256)) % (256);
//	s->b = //color % (256);
}

int		spec_to_int(t_spec *c)
{
	int	new;
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (unsigned int)(c->r);
	g = (unsigned int)(c->g);
	b = (unsigned int)(c->b);
//	new = (r * (65536) + g * (256) + b);
//	return (new);
	return ((r >> 16) + ((g << 16) >> 24) + ((b << 24) >> 24));
}

void		draw_line_p(t_param *param, t_dot *dot1, t_dot *dot2)
{
	float		inc_x;
	float		inc_y;
	float		st_x;
	float		st_y;
	t_spec		st_c;
	t_spec		inc_c;
	float		n_pixels;

	n_pixels = get_inc_n_maxp(dot1, dot2, &inc_x, &inc_y);
	st_x = dot1->x;
	st_y = dot1->y;
	get_spec(&st_c, dot1->color);
	get_color_inc(n_pixels, dot1->color, dot2->color, &inc_c);
	while (n_pixels >= 0)
	{
		if ((st_x > 0) && (st_y > 0) && (st_y < WINDOW_HEIGTH) && (st_x < WINDOW_WIDTH))
			mlx_pixel_put(param->mlx_ptr, param->win_ptr,
				(int)round(st_x), (int)round(st_y), spec_to_int(&st_c));
		inc_st_color(&st_c, &inc_c);
		st_x += inc_x;
		st_y += inc_y;
		n_pixels--;
	}
}


void		draw_box(t_param *param, t_dot *dot1, t_dot *dot4, int color)
{
	t_dot		dot2;
	t_dot		dot3;


	dot2.x = dot4->x;
	dot2.color = 0xFF0000;
	dot2.y = dot1->y;
	dot3.x = dot1->x;
	dot3.color = 0xFF0000;
	dot3.y = dot4->y;
	draw_line_p(param, dot1, &dot2);
	draw_line_p(param, dot1, &dot3);
	draw_line_p(param, dot4, &dot2);
	draw_line_p(param, dot4, &dot3);
}

void		draw_menu(t_param *param, int color)
{
	void		*img_ptr;
	int		x;
	int		y;

	x = WINDOW_H_M;
	y = 15;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Zoom(+-): Mouse wheel");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Shift(Up, Right, Down, Left): WASD/Arrows");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"RotateOxOyOz(+-): QW/AS/ZX");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Projection(iso/paral/restart): I/P");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Oz(+-rev): 1/2/3");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Transparancy: T");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Color change: C");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"EXIT: esc");
	img_ptr = mlx_xpm_file_to_image(param->mlx_ptr, "menu.xpm", &x, &y);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, img_ptr, 0, 0); // destroy and yatayatayta
}
