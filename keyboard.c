/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:59:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 03:12:55 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		rot_net_dot(param, SENS_ROT_K, 'x');
	if (keycode == WKEY)
		rot_net_dot(param, -SENS_ROT_K, 'x');
	if (keycode == AKEY)
		rot_net_dot(param, SENS_ROT_K, 'y');
	if (keycode == SKEY)
		rot_net_dot(param, -SENS_ROT_K, 'y');
	if (keycode == ZKEY)
		rot_net_dot(param, SENS_ROT_K, 'z');
	if (keycode == XKEY)
		rot_net_dot(param, -SENS_ROT_K, 'z');
	if (keycode == KEY1)
		zx_net_dot(param, SENS_Z_MULT_IN);
	if (keycode == KEY2)
		zx_net_dot(param, SENS_Z_MULT_OUT);
}

static void	keyboard_f_norep_ext(int keycode, void *param)
{
	if (keycode == KEY3)
		zx_net_dot(param, -1);
	if (keycode == IKEY)
	{
		new_net_dot(param);
		rot_net_dot(param, 0, 'i');
	}
	if (keycode == SPACE)
		new_net_dot(param);
	if (keycode == ESC)
		free_and_exit(param);
}

int			keyboard_f(int keycode, void *param)
{
	keyboard_f_ext(keycode, param);
	if (keycode == EKEY)
		zm_net_dot(param, SENS_ZOOM_IN, WINDOW_W_C, WINDOW_H_C);
	if (keycode == RKEY)
		zm_net_dot(param, SENS_ZOOM_OUT, WINDOW_W_C, WINDOW_H_C);
	refresh_screen(param);
	return (0);
}

int			keyboard_f_norep(int keycode, void *param)
{
	keyboard_f_norep_ext(keycode, param);
	if (keycode == UKEY)
		change_trs(param, 0);
	if (keycode == TKEY)
		change_trs(param, 1);
	if (keycode == YKEY)
		change_trs(param, 2);
	refresh_screen(param);
	return (0);
}
