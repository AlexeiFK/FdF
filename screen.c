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

#include "libft.h"
#include <stdlib.h>
#include "fdf.h"
#include "mlx.h"
#include "config.h"

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
		draw_line_t(param, dot, dotp);
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
			draw_line_t(param, dot, dot->next);
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
