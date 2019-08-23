/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:57:44 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 01:44:37 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include "config.h"

void	change_trs(t_param *param, int trs)
{
	if (param->file_size < HIDEABLE_MAX)
		param->is_trs = trs;
}

void	refresh_screen(t_param *param)
{
	if (param->is_trs == 0)
		net_dot_c(param);
	else if (param->is_trs == 1)
		tp_dot(param, 0);
	else if (param->is_trs == 2)
		tp_dot(param, 1);
	mlx_put_image_to_window(param->mlx_ptr,
			param->win_ptr, param->img_ptr, 0, 0);
	draw_menu(param, 0xffffff);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
}

void	ch_pixel_put(t_param *param, int x, int y, t_spec *c)
{
	unsigned char	*s;
	int				xm;

	xm = x << 2;
	s = param->s;
	s += (param->size * y);
	s[xm] = c->b;
	s[xm + 1] = c->g;
	s[xm + 2] = c->r;
}
