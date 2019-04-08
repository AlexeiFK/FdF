
#include "mlx.h"
#include "fdf.h"
#include "config.h"
#include <math.h>
#include <stdlib.h>

int		keyboard_f(int keycode, void *param)
{
//	printf("_______________________________%d\n", keycode);
	if (keycode == UP || keycode == WKEY)
		sh_net_dot(param, 0, -SENS_VERT, 0);
	if (keycode == DOWN || keycode == SKEY)
		sh_net_dot(param, 0, SENS_VERT, 0);
	if (keycode == RIGHT || keycode == DKEY)
		sh_net_dot(param, SENS_HOR, 0, 0);
	if (keycode == LEFT || keycode == AKEY)
		sh_net_dot(param, -SENS_HOR, 0, 0);
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
	return (0);
}

void		menu_handler(void *param, int x, int y)
{
	t_dot	*dot1;
	t_dot	*dot2;

	if (x > 1 && x < 101 && y > 25 && y < 55)
	{
		sh_net_dot(param, 0, -SENS_VERT, 0);
		dot1 = create_dot(1, 25, 0, 0);
		dot2 = create_dot(101, 55, 0, 0);
		draw_box(param, dot1, dot2, 0xFF0000);
	}
	if (x > 51 && x < 101 && y > 55 && y < 85)
	{
		dot1 = create_dot(51, 55, 0, 0);
		dot2 = create_dot(101, 85, 0, 0);
		sh_net_dot(param, SENS_HOR, 0, 0);
		draw_box(param, dot1, dot2, 0xFF0000);
	}
	if (x > 1 && x < 50 && y > 55 && y < 85)
	{
		dot1 = create_dot(1, 55, 0, 0);
		dot2 = create_dot(50, 85, 0, 0);
		sh_net_dot(param, -SENS_HOR, 0, 0);
		draw_box(param, dot1, dot2, 0xFF0000);
	}
	if (x > 1 && x < 101 && y > 85 && y < 115)
	{
		dot1 = create_dot(1, 85, 0, 0);
		dot2 = create_dot(101, 115, 0, 0);
		sh_net_dot(param, 0, SENS_VERT, 0);
		draw_box(param, dot1, dot2, 0xFF0000);
	}
	if (x > 1 && x < 101 && y > 270 && y < 290)
	{
		dot1 = create_dot(1, 270, 0, 0);
		dot2 = create_dot(101, 290, 0, 0);
		rot_net_dot(param, 0 , 'i');
		draw_box(param, dot1, dot2, 0xFF0000);
	}
	if (x > 1 && x < 101 && y > 290 && y < 310)
	{
		dot1 = create_dot(1, 270, 0, 0);
		dot2 = create_dot(101, 290, 0, 0);
		new_net_dot(param);
		draw_box(param, dot1, dot2, 0xFF0000);
	}
}

int		mouse_f(int buttom, int x, int y, void *param)
{
	if (buttom == 1)
	{
		menu_handler(param, x, y);
		return (0);
	}
	if (buttom == 4)
		zm_net_dot(param, SENS_ZOOM_IN, x, y);
	if (buttom == 5)
		zm_net_dot(param, SENS_ZOOM_OUT, x, y);
	return (0);
}

