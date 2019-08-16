/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transparent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:48:39 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 18:48:41 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <float.h>
#include "config.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"

void		swap_box(t_box *box1, t_box *box2)
{
	t_dot	*d1;
	t_dot	*d2;
	t_dot	*d3;
	t_dot	*d4;
	int	ctr;

	d1 = box1->dot1;
	d2 = box1->dot2;
	d3 = box1->dot3;
	d4 = box1->dot4;
	ctr = box1->ctr;
	box1->dot1 = box2->dot1;
	box1->dot2 = box2->dot2;
	box1->dot3 = box2->dot3;
	box1->dot4 = box2->dot4;
	box1->ctr = box2->ctr;
	box2->dot1 = d1;
	box2->dot2 = d2;
	box2->dot3 = d3;
	box2->dot4 = d4;
	box2->ctr = ctr;
}

void		sort_box(t_box *box)
{
	t_box	*tmpi;
	t_box	*tmpj;

	tmpi = box;
	while (tmpi)
	{
		tmpj = box;
		while (tmpj->next)
		{
			if (tmpj->ctr > tmpj->next->ctr)
				swap_box(tmpj, tmpj->next);
			tmpj = tmpj->next;
		}
		tmpi = tmpi->next;
	}
}

void		draw_box_new(t_param *param, t_box *box, char diags)
{
	while (box)
	{
		draw_box_n(param, box->dot1, box->dot2, box->dot3, 0);
		draw_box_n(param, box->dot2, box->dot1, box->dot4, 0);
		draw_box_n(param, box->dot3, box->dot1, box->dot4, 0);
		draw_box_n(param, box->dot4, box->dot2, box->dot3, 0);
		draw_line_t(param, box->dot1, box->dot2);
		draw_line_t(param, box->dot1, box->dot3);
		draw_line_t(param, box->dot3, box->dot4);
		draw_line_t(param, box->dot2, box->dot4);
		if (diags)
		{
			draw_line_t(param, box->dot1, box->dot4);
			draw_line_t(param, box->dot3, box->dot2);
		}
		box = box->next;
	}
}

void	get_dep(t_param *param)
{
	t_dot	*dot;

	dot = param->dot;
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	oy_rot(param->dot, M_PI / 2);
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
	while (dot)
	{
		dot->dep = (int)round(dot->x);
		dot = dot->next;
	}
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	oy_rot(param->dot, -M_PI / 2);
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
}

void	tp_dot(t_param *param, char diag)
{
	get_dep(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	param->box = create_box(param);
	sort_box(param->box);
	draw_box_new(param, param->box, diag);
	free_box(&param->box);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}
