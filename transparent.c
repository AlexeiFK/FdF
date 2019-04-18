
#include "config.h"
#include "fdf.h"
#include <math.h>
#include <stdio.h>
#include "mlx.h"

void	print_dots(t_dot *dot)
{
	int i;

	i = 0;
	while (dot)
	{
		printf("(%d)x[%f]y[%f]z[%f]\n", i, dot->x, dot->y, dot->z);
		dot = dot->next;
		i++;
	}
}

void	new_dep_map(t_dot *dot)
{
	int map[WINDOW_WIDTH][WINDOW_HEIGTH];
	int i;
	int j;

	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGTH)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	while (dot)
	{
		map[(int)round(dot->x)][(int)round(dot->y)] = dot->z;
		dot = dot->next;
	}
	i = 0;
	while (i < WINDOW_WIDTH)
	{
		j = 0;
		while (j < WINDOW_HEIGTH)
		{
			if (map[i][j] != 0)
				printf("map[%d][%d] = %d\n", i, j, map[i][j]);
			j++;
		}
		i++;
	}

}

void	ch_pixel_put(t_param *param, int x, int y, t_spec *c)
{
	unsigned char	*s;

	s = param->s;
	s += (param->size * y);
	s[x * 4] = c->b;
	s[x * 4 + 1] = c->g;
	s[x * 4 + 2] = c->r;
//	printf("%d,%d,%d\n", s[x*4], s[x*4+1], s[x*4+2]);
}

void	tp_dot(t_param *param)
{
	unsigned int color;
	int		i;
	int		j;
	unsigned char	*s;
	int		bits;
	int		size;
	int		endian;
	t_spec		spec;
	void		*img_ptr1;

	spec.r = 255;
	spec.g = 0;
	spec.b = 255;
	param->img_ptr = mlx_new_image(param->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGTH);
	param->s = mlx_get_data_addr(param->img_ptr, &bits, &(param->size), &endian);
//	mlx_put_image_to_window(param->mlx_ptr, param->win_ptr, param->img_ptr, 0, 0); // destroy and yatayatayta
	//new_dep_map(param->dot);
	//print_dots(param->dot);
}
