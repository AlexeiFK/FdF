
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "fdf.h"
#include "libft.h"
#include "config.h"


static int	get_inc_n_maxb(int *n_pixels, float *inc_xy)
{
	float		f_pixels[2];
	int		max;
	float		dev;

	if (n_pixels[1] > n_pixels[0])
	{
		f_pixels[0] = n_pixels[0];
		f_pixels[1] = n_pixels[1];
		dev = f_pixels[0] / f_pixels[1];
		inc_xy[0] = inc_xy[0] * dev;
		inc_xy[1] = inc_xy[1] * dev;
		max = n_pixels[1];
	}
	else
	{
		f_pixels[0] = n_pixels[0];
		f_pixels[1] = n_pixels[1];
		dev = f_pixels[1] / f_pixels[0];
		inc_xy[2] = inc_xy[2] * dev;
		inc_xy[3] = inc_xy[3] * dev;
		max = n_pixels[0];
	}
	return (max);
}

static void	fill_dot(t_dot *tmp_d, float st_xy0, float st_xy1, int dep)
{
	tmp_d->x = st_xy0;
	tmp_d->y = st_xy1;
	tmp_d->dep = dep;
}

static void	fill_start(float *st_xy, t_dot *dot1)
{
	st_xy[0] = dot1->x;
	st_xy[1] = dot1->y;
	st_xy[2] = dot1->x;
	st_xy[3] = dot1->y;
}

void		draw_box_n(t_param *param, t_dot *dot1, t_dot *dot2, t_dot *dot3, int color)
{
	float		inc_xy[4];
	float		st_xy[4];
	t_dot		tmp_d[2];
	int		n_pixels[2];
	int		max;

	n_pixels[0] = get_inc_n_maxp(dot1, dot2, &inc_xy[0], &inc_xy[1]);
	n_pixels[1] = get_inc_n_maxp(dot1, dot3, &inc_xy[2], &inc_xy[3]);
	fill_start(st_xy, dot1);
	max = get_inc_n_maxb(n_pixels, inc_xy);
	while (max >= 0)
	{
		fill_dot(&tmp_d[0], st_xy[0], st_xy[1], dot1->dep);
		tmp_d[0].color = color;
		fill_dot(&tmp_d[1], st_xy[2], st_xy[3], dot2->dep);
		tmp_d[1].color = color;
		draw_line_t(param, &tmp_d[0], &tmp_d[1]);
		st_xy[0] += inc_xy[0];
		st_xy[1] += inc_xy[1];
		st_xy[2] += inc_xy[2];
		st_xy[3] += inc_xy[3];
		--(max);
	}
}
