/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:59:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 22:02:11 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include "config.h"
#include <math.h>

static void	keyboard_f_ext(int keycode, void *param)
{
	if (keycode == UP)
		sh_net_dot(param, 0, SENS_VERT, 0);
	if (keycode == DOWN)
		sh_net_dot(param, 0, -SENS_VERT, 0);
	if (keycode == RIGHT)
		sh_net_dot(param, -SENS_HOR, 0, 0);
	if (keycode == LEFT)
		sh_net_dot(param, SENS_HOR, 0, 0);
	if (keycode == QKEY)
		rot_net_dot(param, M_PI / 30, 'x');
	if (keycode == WKEY)
		rot_net_dot(param, -(M_PI / 30), 'x');
	if (keycode == AKEY)
		rot_net_dot(param, M_PI / 30, 'y');
	if (keycode == SKEY)
		rot_net_dot(param, -(M_PI / 30), 'y');
	if (keycode == ZKEY)
		rot_net_dot(param, M_PI / 30, 'z');
	if (keycode == XKEY)
		rot_net_dot(param, -(M_PI / 30), 'z');
}

static void	keyboard_f_ext_ext(int keycode, void *param)
{
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
		rot_net_dot(param, 0, 'i');
	}
	if (keycode == SPACE)
		new_net_dot(param);
}

int			keyboard_f(int keycode, void *param)
{
	int		is_trs;

	is_trs = 0;
	keyboard_f_ext(keycode, param);
	keyboard_f_ext_ext(keycode, param);
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
		free_and_exit(param);
	refresh_screen(param, is_trs);
	return (0);
}
