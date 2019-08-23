/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:36:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 03:20:06 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"
#include "config.h"

int			get_inc_n_maxp(t_dot *dot1, t_dot *dot2, float *inc_x, float *inc_y)
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

void		draw_line_t(t_param *param, t_dot *dot1, t_dot *dot2)
{
	float		inc_xy[2];
	float		st_xy[2];
	t_spec		st_c;
	t_spec		inc_c;
	int			n_pixels;

	n_pixels = get_inc_n_maxp(dot1, dot2, &inc_xy[0], &inc_xy[1]);
	st_xy[0] = dot1->x;
	st_xy[1] = dot1->y;
	get_spec(&st_c, dot1->color);
	get_color_inc(n_pixels, dot1->color, dot2->color, &inc_c);
	while (n_pixels >= 0)
	{
		if ((st_xy[0] > 0) && (st_xy[1] > 0) &&
				(st_xy[1] < WINDOW_HEIGTH) && (st_xy[0] < WINDOW_WIDTH))
			ch_pixel_put(param, (int)st_xy[0], (int)st_xy[1], &st_c);
		inc_st_color(&st_c, &inc_c);
		st_xy[0] += inc_xy[0];
		st_xy[1] += inc_xy[1];
		--n_pixels;
	}
}
