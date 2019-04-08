
#include <stdlib.h>
#include "mlx.h"
#include <math.h>
#include "config.h"
#include "fdf.h"
#include "libft.h"
#include <stdlib.h>

char		**get_xpm()
{
	char	**new;
	int	x = WINDOW_WIDTH;
	int	y = WINDOW_HEIGTH + 6;
	int	i = 0;
	int	j = 0;
	new = (char **)malloc(sizeof(char*) * y);

	while (i < y)
	{
		new[i] = ft_strnew(x);
		ft_memset(new[i], 'a', x);
		i++;
	}
	ft_strcpy(new[0], " 500 500 5 1");
	ft_strcpy(new[1], "` c #ffffff");
	ft_strcpy(new[2], ". c #00ff00");
	ft_strcpy(new[3], "# c #ff0000");
	ft_strcpy(new[4], "a c #000000");
	ft_strcpy(new[5], "b c #0000ff");
	return (new);
}

char		**set_zeros()
{
	char	**new;
	int	x = WINDOW_WIDTH;
	int	y = WINDOW_HEIGTH;
	int	i = 0;

	new = (char **)malloc(sizeof(char*) * y + 10);
	while (i < y)
	{
		new[i] = ft_strnew(x);
		ft_memset(new[i], 'a', x);
		i++;
	}
	new[i] = NULL;
	return (new);
}

static int	get_inc_n_maxp(t_dot *dot1, t_dot *dot2, float *inc_x, float *inc_y)
{
	float		dif_x;
	float		dif_y;
	float		dif_max;

	*inc_x = 1;
	*inc_y = 1;
	if (dot1->x > dot2->x)
		*inc_x = -1;
	if (dot1->y > dot2->y)
		*inc_y = -1;
	dif_x = fabsf(dot2->x - dot1->x);
	dif_y = fabsf(dot2->y - dot1->y);
	if (dif_y > dif_x)
	{
		*inc_x = *inc_x * (dif_x / dif_y);
		return (fabsf(dif_y));
	}
	else
	{
		*inc_y = *inc_y * (dif_y / dif_x);
		return (fabsf(dif_x));
	}
}

void		img_pixel_put(char **img, int x, int y, int color)
{
	img[x][y] = '.';
}

void		draw_line_img(char **img, t_dot *dot1, t_dot *dot2, int color)
{
	float		inc_x;
	float		inc_y;
	float		st_x;
	float		st_y;
	float		n_pixels;

	n_pixels = get_inc_n_maxp(dot1, dot2, &inc_x, &inc_y);
	st_x = dot1->x;
	st_y = dot1->y;
	while (n_pixels >= 0)
	{
		if ((st_x > 0) && (st_y > 0) && (st_y < WINDOW_HEIGTH) && (st_x < WINDOW_WIDTH))
			img_pixel_put(img, (int)round(st_x), (int)round(st_y), color);
		st_x += inc_x;
		st_y += inc_y;
		n_pixels--;
	}
}
