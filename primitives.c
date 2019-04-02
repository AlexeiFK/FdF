/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:31:53 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 22:29:00 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

t_line	*create_line(int start_x, int start_y, int end_x, int end_y)
{
	t_line		*line;

	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	line->x1 = start_x;
	line->y1 = start_y;
	line->x2 = end_x;
	line->y2 = end_y;
	return (line);
}

t_line	*create_line_d(t_dot *start_dot, t_dot *end_dot)
{
	t_line		*line;

	if (!(line = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	line->x1 = start_dot->x;
	line->y1 = start_dot->y;
	line->x2 = end_dot->x;
	line->y2 = end_dot->y;
	return (line);
}

t_dot	*create_dot(int x, int y, int z, int color)
{
	t_dot		*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->y = y;
	dot->z = z;
	dot->color = color;
	dot->next = NULL;
	return (dot);
}

void	add_dot(t_dot **dot, t_dot *new)
{
	if (!dot || !new)
		return ;
	new->next = *dot;
	*dot = new;
}

void	iter_dot(t_dot *dot, void (*f)(t_dot *elem))
{
	while (dot)
	{
		(*f)(dot);
		dot = dot->next;
	}
}

void	free_dot(t_dot **dot)
{
	t_dot	*tmp;
	t_dot	*dtr;

	dtr = *dot;
	while (dtr)
	{
		tmp = dtr->next;
		free(dtr);
		dtr = tmp;
	}
	*dot = NULL;
}

void	free_line(t_dot *dot)
{
}
