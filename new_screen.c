/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 13:01:27 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 21:01:22 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include "config.h"

static void	put_vert(t_dot *dot, void *param, int rows)
{
	void	**params = (void**)param;
	t_dot	*dotp;

	dotp = dot;
	while (dotp->next && (rows))
	{
		dotp = dotp->next;
		rows--;
	}
	while (dotp)
	{
		draw_line_p(param, dot, dotp, dot->color);	//color
		dot = dot->next;
		dotp = dotp->next;
	}
}

static int	out_of_window(t_dot *dot1, t_dot *dot2)
{
	if (!((dot1->x > 0) && (dot1->y > 0) && (dot1->x < WINDOW_WIDTH) && (dot1->y < WINDOW_HEIGTH)))
		if (!((dot2->x > 0) && (dot2->y > 0) && (dot2->x < WINDOW_WIDTH) && (dot2->y < WINDOW_HEIGTH)))
			return (1);
	return (0);
}

void		net_dot(t_dot *dot, void *param)
{
	void	**params = (void**)param;
	t_dot	*tmp;
	int		n_rows;

	n_rows = 1;
	tmp = dot;
	while (dot->next)
	{
		if (dot->row == dot->next->row)
		{
			if (!out_of_window(dot, dot->next))
				draw_line_p(param, dot, dot->next, dot->color); //color
			n_rows++;
		}
		else
		{
			n_rows = 1;
		}
		dot = dot->next;
	}
	put_vert(tmp, param, n_rows);
}

static void	put_vert_char(t_dot *dot, void *param, int rows)
{
	void	**params = (void**)param;
	t_dot	*dotp;

	dotp = dot;
	while (dotp->next && (rows))
	{
		dotp = dotp->next;
		rows--;
	}
	while (dotp)
	{
		draw_line_img(params[4], dot, dotp, dot->color);
		dot = dot->next;
		dotp = dotp->next;
	}
}
void		net_char(t_dot *dot, void *param)
{
	void	**params = (void**)param;
	t_dot	*tmp;
	int		n_rows;

	n_rows = 1;
	tmp = dot;
	while (dot->next)
	{
		if (dot->row == dot->next->row)
		{
			if (!out_of_window(dot, dot->next))
				draw_line_img(params[4], dot, dot->next, 0xFFFFFF);
			n_rows++;
		}
		else
		{
			n_rows = 1;
		}
		dot = dot->next;
	}
	put_vert_char(tmp, param, n_rows);
}

void	put_dots(t_dot *dot, void *param)
{
	void	**params = (void**)param;

	while (dot)
	{
		mlx_pixel_put(params[0], params[1], dot->x, dot->y, 0xFFFFFF);
		dot = dot->next;
	}
}

void	sh_net_dot(t_dot *dot, void *param, int x, int y)
{
	void	**params = (void**)param;

	mlx_clear_window(params[0], params[1]);
	shift(dot, x, y);
//	put_dots(params[2], param);
	net_dot(dot, param);
}

void	zm_net(void *param, float mult, int x, int y)
{
	void	**params = (void**)param;
	int width;
	int height;

	mlx_clear_window(params[0], params[1]);
	zoom(params[2], mult, x, y);
//	put_dots(params[2], param);
	params[4] = get_xpm();
	net_char(params[2], param);
	mlx_destroy_image(params[0], params[3]);
	params[3] = mlx_xpm_to_image(params[0], params[4], &width, &height);
	mlx_put_image_to_window(params[0], params[1], params[3], 0, 0);
}

void	zm_net_dot(void *param, float mult, int x, int y)
{
	void	**params = (void**)param;

	mlx_clear_window(params[0], params[1]);
	zoom(params[2], mult, x, y);
//	put_dots(params[2], param);
	net_dot(params[2], param);
}

void	iso_net_dot(void *param, float angle, int x, int y)
{
	void	**params = (void**)param;

	mlx_clear_window(params[0], params[1]);
	iso_conv(params[2]);
//	put_dots(params[2], param);
	net_dot(params[2], param);
}
void	ag_net_dot(void *param, float angle, int x, int y)
{
	void	**params = (void**)param;

	mlx_clear_window(params[0], params[1]);
	conv(params[2], angle, x, y);
//	put_dots(params[2], param);
	net_dot(params[2], param);
}
