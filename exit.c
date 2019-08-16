/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 21:03:47 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 21:09:45 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
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
