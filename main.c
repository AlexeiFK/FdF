/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 22:33:58 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 23:32:41 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <math.h>
#include "fdf.h"
#include <stdlib.h>
#include <stdio.h>
#include "libft.h"

void	print_dot(t_dot *dot)
{
	printf("x = %d y = %d z = %d color = %x\n",
		   	dot->x, dot->y, dot->z, dot->color);
}

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
	void	*param[2];
	t_dot	*list;

	if (argc != 2)
	{
		ft_putstr("usage:\n");
	}
	list = ft_reader(argv[1]);
	printf("SEG!\n");
	iter_dot(list, print_dot);
	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "FdF");
	param[0] = mlx_ptr;
	param[1] = win_ptr;
	put_dot(list, param);
	mlx_key_hook(win_ptr, do_smth, param);
	mlx_mouse_hook(win_ptr, m_draw, param);
	mlx_loop(mlx_ptr);
	return (0);
}
