/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 19:35:26 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 19:35:36 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "config.h"
#include "fdf.h"

void		draw_menu(t_param *param, int color)
{
	int		x;
	int		y;

	x = WINDOW_H_M;
	y = 15;
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Zoom(+-): Mouse wheel");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Zoom to centre(+-): E/R");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Shift(Up, Right, Down, Left): Arrows");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"RotateOxOyOz(+-): QW/AS/ZX");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Iso projection: I");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Oz(+-rev): 1/2/3");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Hide(with or without diagonals): T/Y");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"Restart: Space");
	mlx_string_put(param->mlx_ptr, param->win_ptr, 102, x+=y, color,
			"EXIT: esc");
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->menu_ptr, 0, 0);
}
