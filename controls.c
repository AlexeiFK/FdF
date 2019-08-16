/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:58:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 19:54:32 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "config.h"
#include <math.h>
#include <stdlib.h>

int		keyboard_f(int keycode, void *param)
{
	int		is_trs;

	is_trs = 0;
//	printf("_______________________________%d\n", keycode);
	if (keycode == UP || keycode == WKEY)
		sh_net_dot(param, 0, SENS_VERT, 0);
	if (keycode == DOWN || keycode == SKEY)
		sh_net_dot(param, 0, -SENS_VERT, 0);
	if (keycode == RIGHT || keycode == DKEY)
		sh_net_dot(param, -SENS_HOR, 0, 0);
	if (keycode == LEFT || keycode == AKEY)
		sh_net_dot(param, SENS_HOR, 0, 0);
	if (keycode == VKEY)
		sh_net_dot(param, 0, 0, 20);
	if (keycode == BKEY)
		sh_net_dot(param, 0, 0, -20);
	if (keycode == QKEY)
		rot_net_dot(param, M_PI / 30 , 'x');
	if (keycode == EKEY)
		rot_net_dot(param, M_PI / 30 , 'y');
	if (keycode == ZKEY)
		rot_net_dot(param, M_PI / 30 , 'z');
	if (keycode == KKEY)
		zx_net_dot(param, 1.1);
	if (keycode == LKEY)
		zx_net_dot(param, 0.9);
	if (keycode == OKEY)
		zx_net_dot(param, -1);
	if (keycode == ESC)
		exit(0);
	refresh_screen(param, is_trs);
	return (0);
}

void		menu_handler(void *param, int x, int y, int *is_trs)
{
	if (x > 1 && x < 50 && y > 115 && y < 135)
		zx_net_dot(param, 0.9);
	if (x > 50 && x < 101 && y > 115 && y < 135)
		zx_net_dot(param, 1.1);
	if (x > 1 && x < 101 && y > 135 && y < 155)
		zx_net_dot(param, -1);
	if (x > 1 && x < 50 && y > 225 && y < 245)
		rot_net_dot(param, -M_PI / 32 , 'x');
	if (x > 1 && x < 50 && y > 245 && y < 265)
		rot_net_dot(param, -M_PI / 32 , 'y');
	if (x > 1 && x < 50 && y > 265 && y < 290)
		rot_net_dot(param, -M_PI / 32 , 'z');
	if (x > 50 && x < 101 && y > 225 && y < 245)
		rot_net_dot(param, M_PI / 32 , 'x');
	if (x > 50 && x < 101 && y > 245 && y < 265)
		rot_net_dot(param, M_PI / 32 , 'y');
	if (x > 50 && x < 101 && y > 265 && y < 290)
		rot_net_dot(param, M_PI / 32 , 'z');
	if (x > 1 && x < 101 && y > 290 && y < 310)
	{
		new_net_dot(param);
		rot_net_dot(param, 0 , 'i');
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
		exit(0);
}

int		mouse_f(int buttom, int x, int y, void *param)
{
	int		is_trs;

	is_trs = 0;
	if (buttom == 1)
	{
		if (x > 1 && x < 101 && y > 25 && y < 55)
			sh_net_dot(param, 0, SENS_VERT, 0);
		if (x > 51 && x < 101 && y > 55 && y < 85)
			sh_net_dot(param, -SENS_HOR, 0, 0);
		if (x > 1 && x < 50 && y > 55 && y < 85)
			sh_net_dot(param, SENS_HOR, 0, 0);
		if (x > 1 && x < 101 && y > 85 && y < 115)
			sh_net_dot(param, 0, -SENS_VERT, 0);
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
