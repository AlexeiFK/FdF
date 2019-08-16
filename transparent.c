
#include <limits.h>
#include <float.h>
#include "config.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include "mlx.h"
#include "libft.h"

/*
void	print_dots(t_param *param, t_dot *dot)
{
	int i;
	int zzz;
	int	xxx;
	char	*s1;
	char	*s;

	i = 0;
	while (dot)
	{
//		zzz = (int)dot->x;
		xxx = (int)dot->dep;
//		s1 = ft_strjoin(ft_itoa(zzz), "=x | dep=");
		s = ft_strjoin("d", ft_itoa(xxx));
//		printf("(%d)x[%f]y[%f]z[%f]\n", i, dot->x, dot->y, dot->z);
		mlx_string_put(param->mlx_ptr, param->win_ptr, (int)dot->x, (int)dot->y, 0xffffff, s);
		dot = dot->next;
		i++;
	}
}
*/

void	ch_pixel_put(t_param *param, int x, int y, t_spec *c)
{
	unsigned char	*s;

	s = param->s;
	s += (param->size * y);
	s[x * 4] = c->b;
	s[x * 4 + 1] = c->g;
	s[x * 4 + 2] = c->r;
}

void	get_dep(t_param *param)
{
	t_dot	*dot;

	dot = param->dot;
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	oy_rot(param->dot, M_PI / 2);
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
	while (dot)
	{
		dot->dep = (int)round(dot->x);
		dot = dot->next;
	}
	shift(param->dot, -WINDOW_W_C, -WINDOW_H_C, 0);
	oy_rot(param->dot, -M_PI / 2);
	shift(param->dot, WINDOW_W_C, WINDOW_H_C, 0);
}

void	tp_dot(t_param *param, char diag)
{
	static int	is_new = 1;
	get_dep(param);
	ft_bzero(param->s, 4 * WINDOW_HEIGTH * WINDOW_WIDTH);
	if (/*is_new ==*/ 1)
	{
		is_new = 0;
		param->box = create_box(param);
	}
	sort_box(param->box);
	draw_box_new(param, param->box, diag);
	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	draw_menu(param, 0xffffff);
}
