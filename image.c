/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 18:57:44 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 20:07:43 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "libft.h"

void	refresh_screen(t_param *param, int is_trs)
{
	if (is_trs == 0)
		net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0);
	draw_menu(param, 0xffffff);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
}

void	ch_pixel_put(t_param *param, int x, int y, t_spec *c)
{
	unsigned char	*s;
	int				xm;

	xm = x * 4;
	s = param->s;
	s += (param->size * y);
	s[xm] = c->b;
	s[xm + 1] = c->g;
	s[xm + 2] = c->r;
}
