/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 21:21:57 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"
#include "config.h"


static void	find_x_y(t_dot *dot, int *x, int *y)
{
	*x = dot->x;
	*y = dot->y;
	while (dot->next)
	{
		//max
		dot = dot->next;
	}
}

void		test123(t_dot *dot)
{
	while (dot)
	{
		printf("x = %f, y = %f\n", dot->x, dot->y);
		dot = dot->next;
	}
}

static void	standard_placement(t_param *param, int zmult, t_colors *color)
{
	int	x;
	int	y;
	int	shx;
	int	shy;
	int	min;

	find_x_y(param->dot, &x, &y);
	if (((WINDOW_WIDTH - 150) / y) > ((WINDOW_HEIGTH - 150) / x))
		min = (WINDOW_HEIGTH - 150) / x;
	else
		min = (WINDOW_WIDTH - 150) / y;
	zoom_z(param->dot, min, zmult);
	zoom_z(param->res, min, zmult);
	shx = (WINDOW_WIDTH / 2) - (x * min / 2);
	shy = (WINDOW_HEIGTH / 2) - (y * min / 2);
	shift(param->dot, shx, shy, 0);
	shift(param->res, shx, shy, 0);
	net_dot(param);
	draw_menu(param, 0xFFFFFF);
}

static void	mlx_setup(char *filename, t_param *param, t_colors *colors)
{
	param->res = NULL;

	if (colors->top != NULL)
		param->dot = ft_reader(filename, colors);
	else
		param->dot = ft_reader(filename, NULL);
	ft_cpy(&(param->res), param->dot);
	param->clr = colors;
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGTH, W_NAME);
}

static void	usage_msg(void)
{
	ft_putstr("usage: ./fdf [filename] [color_bot] ");
	ft_putstr("[color_mid] [color_top]\n");
	exit(0);
}

int		main(int argc, char **argv)
{
	t_param 	param;
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
	standard_placement(&param, AT_MULT, &colors);
	mlx_key_hook(param.win_ptr, keyboard_f, (void*)(&param));
	mlx_mouse_hook(param.win_ptr, mouse_f, (void*)(&param));
	mlx_loop(param.mlx_ptr);
	return (0);
}
