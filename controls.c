/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:58:03 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 20:43:16 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "config.h"
#include <math.h>
#include <stdlib.h>

#include <stdio.h>

int		keyboard_f(int keycode, void *param)
{
	int		is_trs;

	is_trs = 0;
	if (keycode == UP)
		sh_net_dot(param, 0, SENS_VERT, 0);
	if (keycode == DOWN)
		sh_net_dot(param, 0, -SENS_VERT, 0);
	if (keycode == RIGHT)
		sh_net_dot(param, -SENS_HOR, 0, 0);
	if (keycode == LEFT)
		sh_net_dot(param, SENS_HOR, 0, 0);
	if (keycode == QKEY)
		rot_net_dot(param, M_PI / 30 , 'x');
	if (keycode == WKEY)
		rot_net_dot(param, - (M_PI / 30) , 'x');
	if (keycode == AKEY)
		rot_net_dot(param, M_PI / 30 , 'y');
	if (keycode == SKEY)
		rot_net_dot(param, - (M_PI / 30) , 'y');
	if (keycode == ZKEY)
		rot_net_dot(param, M_PI / 30 , 'z');
	if (keycode == XKEY)
		rot_net_dot(param, - (M_PI / 30) , 'z');
	if (keycode == KEY1)
		zx_net_dot(param, 1.1);
	if (keycode == KEY2)
		zx_net_dot(param, 0.9);
	if (keycode == KEY3)
		zx_net_dot(param, -1);
	if (keycode == EKEY)
		zm_net_dot(param, SENS_ZOOM_IN, WINDOW_W_C, WINDOW_H_C);
	if (keycode == RKEY)
		zm_net_dot(param, SENS_ZOOM_OUT, WINDOW_W_C, WINDOW_H_C);
	if (keycode == IKEY)
	{
		new_net_dot(param);
		rot_net_dot(param, 0 , 'i');
	}
	if (keycode == SPACE)
		new_net_dot(param);
	if (keycode == TKEY)
	{
		is_trs = 1;
		tp_dot(param, 0);
	}
	if (keycode == YKEY)
	{
		is_trs = 1;
		tp_dot(param, 1);
	}
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
