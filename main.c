/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/30 17:52:35 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "Fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	print_dot(t_dot *dot)
{
	printf("x = %d y = %d\n", dot->x, dot->y);
}

int		do_smth(int keycode, void *param)
{
/*	static int	x = 0;
	static int	y = 0;
	void	**params = (void**)param;
	mlx_pixel_put(params[0], params[1], x, y, 0xFFFFFF);
	x++;
	y++;
	*/
	if (keycode == 53)
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
//	printf("buttom = %d\n", buttom);
	if (p_x == -1)
	{
		p_x = x;
		p_y = y;
	}
	else
	{
		dot1 = create_dot(p_x, p_y);
		dot2 = create_dot(x, y);
		draw_line_p(param, dot1, dot2, color);
		p_x = x;
		p_y = y;
		free(dot1); //
		free(dot2); //
	}
	return (0);
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	*line;
	t_dot	*dots[5];
	void	*param[2];


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	param[0] = mlx_ptr;
	param[1] = win_ptr;
	/*
	dots[0] = create_dot(65, 450);
	dots[1] = create_dot(250, 35);
	dots[2] = create_dot(435, 450);
	dots[3] = create_dot(30, 180);
	dots[4] = create_dot(470, 180);
	draw_line_p(param, dots[0], dots[1], 0xFFFFFF);
	draw_line_p(param, dots[1], dots[2], 0xFFFFFF);
	draw_line_p(param, dots[2], dots[3], 0xFFFFFF);
	draw_line_p(param, dots[3], dots[4], 0xFFFFFF);
	draw_line_p(param, dots[4], dots[0], 0xFFFFFF);
	*/
//	mlx_loop(mlx_ptr);
	mlx_key_hook(win_ptr, do_smth, param);
	mlx_mouse_hook(win_ptr, m_draw, param);
//	mlx_hook(win_ptr, 2, 0, do_smth, (void*)0);
	/*
	line = create_line_d(dots[0], dots[1]);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line_d(dots[1], dots[2]);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line_d(dots[2], dots[3]);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line_d(dots[3], dots[4]);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line_d(dots[4], dots[0]);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	*/
	mlx_loop(mlx_ptr);
	return (0);
}
