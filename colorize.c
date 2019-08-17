/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 22:06:47 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/17 23:14:04 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void	find_max_min(t_dot *dot, int *max, int *min)
{
	int	t_max;
	int	t_min;

	t_max = dot->z;
	t_min = dot->z;
	while (dot)
	{
		if (dot->z > t_max)
			t_max = dot->z;
		if (dot->z < t_min)
			t_min = dot->z;
		dot = dot->next;
	}
	*max = t_max;
	*min = t_min;
}

void	ft_paint_dots_up(t_dot *dot, t_colors *c, int start, int end)
{
	int		i;
	t_spec	st_c;
	t_spec	inc;
	t_dot	*tmp;

	i = start;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc(abs(end - start),
			strtol(c->mid, NULL, 16), strtol(c->top, NULL, 16), &inc);
	while (i <= end)
	{
		tmp = dot;
		while (tmp)
		{
			if (tmp->z == i)
				tmp->color =
					(((int)st_c.r << 16) | ((int)st_c.g << 8) | (int)st_c.b);
			tmp = tmp->next;
		}
		i++;
		inc_st_color(&st_c, &inc);
	}
}

void	ft_paint_dots_down(t_dot *dot, t_colors *c, int start, int end)
{
	int		i;
	t_spec	st_c;
	t_spec	inc;
	t_dot	*tmp;

	i = end;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc(abs(start - end),
			strtol(c->mid, NULL, 16), strtol(c->bot, NULL, 16), &inc);
	while (i >= start)
	{
		tmp = dot;
		while (tmp)
		{
			if (tmp->z == i)
				tmp->color =
					(((int)st_c.r << 16) | ((int)st_c.g << 8) | (int)st_c.b);
			tmp = tmp->next;
		}
		i--;
		inc_st_color(&st_c, &inc);
	}
}

void	ft_colorize(t_dot *dot, t_colors *c)
{
	int	max;
	int	min;
	int	mid;

	find_max_min(dot, &max, &min);
	mid = (max + min) / 2;
	ft_paint_dots_up(dot, c, mid, max);
	ft_paint_dots_down(dot, c, min, mid);
}
