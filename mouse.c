/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 22:00:20 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/17 23:19:29 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	menu_handler_ext(void *param, int x, int y)
{
	if (x > 1 && x < 50 && y > 115 && y < 135)
		zx_net_dot(param, 0.9);
	if (x > 50 && x < 101 && y > 115 && y < 135)
		zx_net_dot(param, 1.1);
	if (x > 1 && x < 101 && y > 135 && y < 155)
		zx_net_dot(param, -1);
	if (x > 1 && x < 50 && y > 225 && y < 245)
		rot_net_dot(param, -SENS_ROT_M, 'x');
	if (x > 1 && x < 50 && y > 245 && y < 265)
		rot_net_dot(param, -SENS_ROT_M, 'y');
	if (x > 1 && x < 50 && y > 265 && y < 290)
		rot_net_dot(param, -SENS_ROT_M, 'z');
	if (x > 50 && x < 101 && y > 225 && y < 245)
		rot_net_dot(param, SENS_ROT_M, 'x');
	if (x > 50 && x < 101 && y > 245 && y < 265)
		rot_net_dot(param, SENS_ROT_M, 'y');
	if (x > 50 && x < 101 && y > 265 && y < 290)
		rot_net_dot(param, SENS_ROT_M, 'z');
}

void		menu_handler(void *param, int x, int y, int *is_trs)
{
	menu_handler_ext(param, x, y);
	if (x > 1 && x < 101 && y > 290 && y < 310)
	{
		new_net_dot(param);
		rot_net_dot(param, 0, 'i');
	}
	if (x > 1 && x < 101 && y > 310 && y < 330)
		new_net_dot(param);
	if (x > 1 && x < 101 && y > 335 && y < 355)
	{
		*is_trs = 1;
		tp_dot(param, 0);
	}
	if (x > 1 && x < 101 && y > 355 && y < 375)
	{
		*is_trs = 1;
		tp_dot(param, 1);
	}
	if (x > 1 && x < 101 && y > 375 && y < 395)
		free_and_exit(param);
}

int			mouse_f(int buttom, int x, int y, void *param)
{
	int		is_trs;

	is_trs = 0;
	if (buttom == 1)
	{
		if (x > 1 && x < 101 && y > 25 && y < 55)
			sh_net_dot(param, 0, SENS_VERT_M, 0);
		if (x > 51 && x < 101 && y > 55 && y < 85)
			sh_net_dot(param, -SENS_HOR_M, 0, 0);
		if (x > 1 && x < 50 && y > 55 && y < 85)
			sh_net_dot(param, SENS_HOR_M, 0, 0);
		if (x > 1 && x < 101 && y > 85 && y < 115)
			sh_net_dot(param, 0, -SENS_VERT_M, 0);
		if (x > 1 && x < 101 && y > 155 && y < 180)
			zm_net_dot(param, SENS_ZOOM_IN, WINDOW_W_C, WINDOW_H_C);
		if (x > 1 && x < 101 && y > 180 && y < 205)
			zm_net_dot(param, SENS_ZOOM_OUT, WINDOW_W_C, WINDOW_H_C);
		menu_handler(param, x, y, &is_trs);
	}
	if (buttom == 4)
		zm_net_dot(param, SENS_ZOOM_IN, x, y);
	if (buttom == 5)
		zm_net_dot(param, SENS_ZOOM_OUT, x, y);
	refresh_screen(param, is_trs);
	return (0);
}
