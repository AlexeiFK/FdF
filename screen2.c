
#include <math.h>
#include "config.h"
#include "fdf.h"
#include "mlx.h"
#include "libft.h"
#include <stdlib.h>

void	sh_net_dot(t_param *param, int x, int y, int z)
{
//	clear_and_rest(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	shift(param->dot, x, y, z);
	net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}

void	zm_net_dot(t_param *param, float mult, int x, int y)
{
//	clear_and_rest(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	zoom(param->dot, mult, x, y);
	net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}

void	rot_net_dot(t_param *param, float angle, char axis)
{
	//clear_and_rest(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	if (axis == 'x')
		ox_rot(param->dot, angle);
	if (axis == 'y')
		oy_rot(param->dot, angle);
	if (axis == 'z')
		oz_rot(param->dot, angle);
	if (axis == 'i')
	{
		oz_rot(param->dot, M_PI / 4);
		ox_rot(param->dot, asin(tan(M_PI / 6)));
	}
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
	net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}

void	new_net_dot(t_param *param)
{
//	clear_and_rest(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	free(param->dot);
	param->dot = NULL;	//norm free
	ft_cpy(&(param->dot), param->res);
	net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}

void	zx_net_dot(t_param *param, float mult)
{
	static float	m = 1;

	m *= mult;
	//clear_and_rest(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	free(param->dot);
	param->dot = NULL;	//norm free
	ft_cpy(&(param->dot), param->res);
	zoom_z(param->dot, 1, m);
	rot_net_dot(param, 0, 'i');
	net_dot_c(param);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}
