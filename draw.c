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
#include "config.h"

static int	get_inc_n_maxp(t_dot *dot1, t_dot *dot2, float *inc_x, float *inc_y)
{
	float		dif_x;
	float		dif_y;
	float		dif_max;

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

void		draw_line_p(t_param *param, t_dot *dot1, t_dot *dot2, int color)
{
	float		inc_x;
	float		inc_y;
	float		st_x;
	float		st_y;
	float		n_pixels;

	n_pixels = get_inc_n_maxp(dot1, dot2, &inc_x, &inc_y);
	st_x = dot1->x;
	st_y = dot1->y;
	while (n_pixels >= 0)
	{
		if ((st_x > 0) && (st_y > 0) && (st_y < WINDOW_HEIGTH) && (st_x < WINDOW_WIDTH))
			mlx_pixel_put(param->mlx_ptr, param->win_ptr,
				(int)round(st_x), (int)round(st_y), color);
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
	dot2.y = dot1->y;
	dot3.x = dot1->x;
	dot3.y = dot4->y;
	draw_line_p(param, dot1, &dot2, color);
	draw_line_p(param, dot1, &dot3, color);
	draw_line_p(param, dot4, &dot2, color);
	draw_line_p(param, dot4, &dot3, color);
}

void		draw_menu(t_param *param, int color)
{
	void		*img_ptr;
	int		x;
	int		y;

	img_ptr = mlx_xpm_file_to_image(param->mlx_ptr, "menu.xpm", &x, &y);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, img_ptr, 0, 0); // destroy and yatayatayta
}
