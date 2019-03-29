/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/29 22:14:55 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "Fdf.h"
#include <stdlib.h>
#include <stdio.h>


int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_line	*line;
	t_dot	*dots[5];


	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	dots[0] = create_dot(65, 450);
	dots[1] = create_dot(250, 35);
	dots[2] = create_dot(435, 450);
	dots[3] = create_dot(30, 180);
	dots[4] = create_dot(470, 180);


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

/*
	line = create_line(65, 450, 250, 35);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line(250, 35, 435, 450);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line(435, 450, 30, 180);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line(30, 180, 470, 180);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	line = create_line(470, 180, 65, 450);
	draw_line(mlx_ptr, win_ptr, line, 0xFFFFFF);
	*/
	mlx_loop(mlx_ptr);
	return (0);
}
