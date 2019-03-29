/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:36:57 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/29 21:40:52 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "Fdf.h"

static void		get_inc_n_max(t_line *line, float *inc_x, float *inc_y, float *n_pixels)
{
	float		dif_x;
	float		dif_y;
	float		dif_max;

	*inc_x = 1;
	*inc_y = 1;
	if (line->x1 > line->x2)
		*inc_x = -1;
	if (line->y1 > line->y2)
		*inc_y = -1;
	dif_x = abs(line->x2 - line->x1);
	dif_y = abs(line->y2 - line->y1);
	if (dif_y > dif_x)
	{
		*inc_x = *inc_x * (dif_x / dif_y);
		*n_pixels = fabsf(dif_y);
	}
	else if (dif_x >= dif_y)
	{
		*inc_y = *inc_y * (dif_y / dif_x);
		*n_pixels = fabsf(dif_x);
	}
}

void			draw_line(void *mlx_ptr, void *win_ptr, t_line *line, int color)
{
	float		inc_x;
	float		inc_y;
	float		st_x;
	float		st_y;
	float		n_pixels;

	get_inc_n_max(line, &inc_x, &inc_y, &n_pixels);
	st_x = line->x1;
	st_y = line->y1;
	while (n_pixels > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr,
				(int)round(st_x), (int)round(st_y), color);
		st_x += inc_x;
		st_y += inc_y;
		n_pixels--;
	}
}
