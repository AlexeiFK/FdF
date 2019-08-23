/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:35:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 03:38:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "fdf.h"

void		is_hideable(t_param *param, int color, int x)
{
	if (param->file_size < HIDEABLE_MAX)
		mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x, color,
			"Hide(w/ or w/o diagonals, return to normal): T/Y/U");
	else
		mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x, color,
			"MAP IS TOO BIG TO HIDE!!!");
}

void		draw_menu(t_param *param, int color)
{
	int		x;
	int		y;

	x = WINDOW_H_M;
	y = 15;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Zoom(+-): Mouse wheel");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Zoom to centre(+-): E/R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Shift(Up, Right, Down, Left): Arrows");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"RotateOxOyOz(+-): QW/AS/ZX");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Iso projection: I");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Oz(+-rev): 1/2/3");
	x += y;
	is_hideable(param, color, x);
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"Restart: Space");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x += y, color,
			"EXIT: esc");
	mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->menu_ptr, 0, 0);
}
