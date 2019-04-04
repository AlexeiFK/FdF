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

/*
void	print_dot(t_dot *dot)
{
	printf("x = %d y = %d z = %d color = %x\n",
		   	dot->x, dot->y, dot->z, dot->color);
}
*/
void	put_dot(t_dot *dot, void *param)
{
	void	**params = (void**)param;

	while (dot)
	{
		mlx_string_put(params[0], params[1], dot->x * 30, dot->y * 30, dot->color, ft_itoa(dot->z));
		dot = dot->next;
	}
}

int		do_smth(int keycode, void *param)
{
	void	**params = (void**)param;

//	printf("_______________________________%d\n", keycode);
	if (keycode == UP || keycode == WKEY)
		sh_net_dot(params[2], param, 0, -SENS_VERT);
	if (keycode == DOWN || keycode == SKEY)
		sh_net_dot(params[2], param, 0, SENS_VERT);
	if (keycode == RIGHT || keycode == DKEY)
		sh_net_dot(params[2], param, SENS_HOR, 0);
	if (keycode == LEFT || keycode == AKEY)
		sh_net_dot(params[2], param, -SENS_HOR, 0);
	if (keycode == QKEY)
		ag_net_dot(param, M_PI / 20, 0, 0);
//		zm_net_dot(param, 1.1, WINDOW_WIDTH / 2, WINDOW_HEIGTH / 2);
	if (keycode == EKEY)
		ag_net_dot(param, M_PI / 20 * (-1), 0, 0);
	//	zm_net_dot(param, 0.9, WINDOW_WIDTH / 2, WINDOW_HEIGTH / 2);
	if (keycode == ZKEY)
		ag_net_dot(param, M_PI / 20, WINDOW_WIDTH / 2, WINDOW_HEIGTH / 2);
	if (keycode == CKEY)
		ag_net_dot(param, M_PI / 20 * (-1), WINDOW_WIDTH / 2, WINDOW_HEIGTH / 2);
	if (keycode == ESC)
		exit(0);
	return (0);
}

int		m_draw(int buttom, int x, int y, void *param)
{
	void	**params = (void**)param;
	t_dot		*dot1;
	t_dot		*dot2;
	static int	p_x = -1;
	static int	p_y = -1;
	int			color;
	if (buttom == 2)
		color = 0xFF0000;
	if (buttom == 1)
		color = 0x00FF00;
	if (buttom == 3)
		color = 0xFFFF00;
	if (buttom == 4)
	{
		zm_net_dot(param, SENS_ZOOM_IN, x, y);
		return (0);
	}
	if (buttom == 5)
	{
		zm_net_dot(param, SENS_ZOOM_OUT, x, y);
		return (0);
	}
	if (p_x == -1)
	{
		p_x = x;
		p_y = y;
	}
	else
	{
		dot1 = create_dot(p_x, p_y, 0, 0);
		dot2 = create_dot(x, y, 0, 0);
		draw_line_p(param, dot1, dot2, color);
		p_x = x;
		p_y = y;
		free(dot1); //
		free(dot2); //
	}
	return (0);
}

int		main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*win_ptr;
//	t_line	*line;
	t_dot	*dots[5];
	void	*param[3];
	t_dot	*list;
	t_dot	*list2;

	if (argc != 2)
	{
		ft_putstr("usage:\n");
		return (0);
	}
	list = ft_reader(argv[1]);
//	iter_dot(list, print_dot);
	list2 = ft_cpy(list);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGTH, "FdF");
	param[0] = mlx_ptr;
	param[1] = win_ptr;
	param[2] = list;
//	put_dot(list, param);
	zoom_z(list, 30);
	shift(list, 0, 0);
	net_dot(list, param);
//	zoom(list2, 20);
//	shift(list2, 20, 200);
//	net_dot(list2, param);
	mlx_key_hook(win_ptr, do_smth, param);
	mlx_mouse_hook(win_ptr, m_draw, param);
	mlx_loop(mlx_ptr);
	return (0);
}
