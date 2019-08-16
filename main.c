/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 21:47:07 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <float.h>
#include "mlx.h"
#include <math.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "config.h"

static void	standard_placement(t_param *param, float zmult)
{
	float	x;
	float	y;
	int		shx;
	int		shy;
	float	min;

	x = param->dot->x;
	y = param->dot->y;
	if (((WINDOW_WIDTH - 150) / x) > ((WINDOW_HEIGTH - 150) / y))
		min = (WINDOW_HEIGTH - 150) / y;
	else
		min = (WINDOW_WIDTH - 150) / x;
	zoom_z(param->dot, min, zmult);
	zoom_z(param->res, min, zmult);
	shx = (WINDOW_WIDTH / 2) - (x * min / 2);
	shy = (WINDOW_HEIGTH / 2) - (y * min / 2);
	shift(param->dot, shx, shy, 0);
	shift(param->res, shx, shy, 0);
	refresh_screen(param, 0);
}

static void	mlx_setup(char *filename, t_param *param, t_colors *colors)
{
	int	bits;
	int	endian;

	param->res = NULL;
	if (colors->top != NULL)
		param->dot = ft_reader(filename, colors);
	else
		param->dot = ft_reader(filename, NULL);
	ft_cpy(&(param->res), param->dot);
	param->clr = colors;
	param->mlx_ptr = mlx_init();
	param->win_ptr =
		mlx_new_window(param->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGTH, W_NAME);
	param->img_ptr = mlx_new_image(param->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGTH);
	param->menu_ptr =
		mlx_xpm_file_to_image(param->mlx_ptr, "menu.xpm", &endian, &bits);
	param->mult = 1;
	param->s = (unsigned char*)
		mlx_get_data_addr(param->img_ptr, &bits, &(param->size), &endian);
}

int			main(int argc, char **argv)
{
	t_param		param;
	t_colors	colors;

	colors.bot = NULL;
	colors.mid = NULL;
	colors.top = NULL;
	if (argc != 2 && argc != 5)
		usage_msg();
	if (argc == 5)
	{
		colors.bot = argv[2];
		colors.mid = argv[3];
		colors.top = argv[4];
	}
	mlx_setup(argv[1], &param, &colors);
	standard_placement(&param, AT_MULT);
	mlx_key_hook(param.win_ptr, keyboard_f, (void*)(&param));
	mlx_mouse_hook(param.win_ptr, mouse_f, (void*)(&param));
	mlx_loop(param.mlx_ptr);
	return (0);
}
