/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_msgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 22:02:35 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/23 05:14:34 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include "mlx.h"

void	free_and_exit(t_param *param)
{
	free_dot(&param->dot);
	free_dot(&param->res);
	mlx_destroy_window(param->mlx_ptr, param->win_ptr);
	mlx_destroy_image(param->mlx_ptr, param->img_ptr);
	mlx_destroy_image(param->mlx_ptr, param->menu_ptr);
	exit(0);
}

void	usage_msg(void)
{
	ft_putstr("usage: ./fdf [filename] [color_bot] ");
	ft_putstr("[color_mid] [color_top]\n");
	exit(0);
}

void	error_file_msg(void)
{
	ft_putstr("File error\n");
	exit(0);
}
