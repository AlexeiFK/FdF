/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:55:48 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 01:49:39 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "config.h"
#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

void	sh_net_dot(t_param *param, int x, int y, int z)
{
	shift(param->dot, x, y, z);
}

void	zm_net_dot(t_param *param, float mult, int x, int y)
{
	zoom(param->dot, mult, x, y);
}

void	rot_net_dot(t_param *param, float angle, char axis)
{
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	if (axis == 'x')
		ox_rot(param->dot, angle);
	if (axis == 'y')
		oy_rot(param->dot, angle);
	if (axis == 'z')
		oz_rot(param->dot, angle);
	if (axis == 'i')
	{
		oz_rot(param->dot, M_PI / 4);
		ox_rot(param->dot, asin(tan(M_PI / 6)));
	}
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
}

void	new_net_dot(t_param *param)
{
	param->mult = 1;
	param->is_trs = 0;
	free_dot(&param->dot);
	param->dot = NULL;
	ft_cpy(&(param->dot), param->res);
}

void	zx_net_dot(t_param *param, float mult)
{
	param->mult *= mult;
	free_dot(&param->dot);
	param->dot = NULL;
	ft_cpy(&(param->dot), param->res);
	zoom_z(param->dot, 1, param->mult);
	rot_net_dot(param, 0, 'i');
}
