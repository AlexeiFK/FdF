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

#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "config.h"

static void	put_vert(t_dot *dot, t_param *param, int rows)
{
	t_dot	*dotp;

	dotp = dot;
	while (dotp->next && (rows))
	{
		dotp = dotp->next;
		rows--;
	}
	while (dotp)
	{
		draw_line_p(param, dot, dotp);	//color
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

void		net_dot(t_param *param)
{
	t_dot	*tmp;
	int		n_rows;
	t_dot	*dot;

	dot = param->dot;
	n_rows = 1;
	tmp = dot;
	while (dot->next)
	{
		if (dot->row == dot->next->row)
		{
	//		if (!out_of_window(dot, dot->next))
			draw_line_p(param, dot, dot->next); //color
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

static void	put_vert_c(t_dot *dot, t_param *param, int rows)
{
	t_dot	*dotp;

	dotp = dot;
	while (dotp->next && (rows))
	{
		dotp = dotp->next;
		rows--;
	}
	while (dotp)
	{
		draw_line_t(param, dot, dotp);	//color
		dot = dot->next;
		dotp = dotp->next;
	}
}

void		net_dot_c(t_param *param)
{
	t_dot	*tmp;
	int		n_rows;
	t_dot	*dot;

	dot = param->dot;
	n_rows = 1;
	tmp = dot;
	while (dot->next)
	{
		if (dot->row == dot->next->row)
		{
	//		if (!out_of_window(dot, dot->next))
			draw_line_t(param, dot, dot->next); //color
			n_rows++;
		}
		else
		{
			n_rows = 1;
		}
		dot = dot->next;
	}
	put_vert_c(tmp, param, n_rows);
}

void	clear_and_rest(t_param *param)
{
	mlx_clear_window(param->mlx_ptr, param->win_ptr);
	draw_menu(param, 0xFFFFFF); //add color
}
