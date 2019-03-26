/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/26 23:06:31 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		i;
	int		j;


	i = 0;
	j = 0;
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
//	mlx_string_put(mlx_ptr, win_ptr, 250, 250, 0xFFFFFF, "FdF");
	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
		i++;
		j++;
	}
	i = 0;
	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
		i++;
		j--;
	}
	i = 0;
	j = 150;
	while (i < 50)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
		i++;
		j++;
	}
	while (i < 100)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
		i++;
		j--;
	}
	while (i > 0)
	{
		mlx_pixel_put(mlx_ptr, win_ptr, i, j, 0xFFFFFF);
		i--;
		j++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
