/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 23:35:31 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

void	draw_line(void *mlx_ptr, void *win_ptr, int *crd, int color)
{
	int	x_str;
	int	y_str;
	int	x_end;
	int	y_end;
	int	x_inc;
	int	y_inc;

	x_str = crd[0];
	y_str = crd[1];
	x_end = crd[2];
	y_end = crd[3];
	x_inc = 1;
	y_inc = 1;
	if (x_str > x_end)
		x_inc = -1;
	if (y_str > y_end)
		y_inc = -1;
	while ((x_str != x_end) && (y_str != y_end))
	{
		mlx_pixel_put(mlx_ptr, win_ptr, x_str, y_str, color);
		x_str += x_inc;
		y_str += y_inc;
	}
}

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		j;
	int		crd[4];


	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	crd[0] = 0;
	crd[1] = 0;
	crd[2] = 300;
	crd[3] = 300;	
	draw_line(mlx_ptr, win_ptr, crd, 0xFFFFFF);
	crd[0] = 200;
	crd[1] = 200;
	crd[2] = 0;
	crd[3] = 0;
	draw_line(mlx_ptr, win_ptr, crd, 0x008000);
	mlx_loop(mlx_ptr);
	return (0);
}
