/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   primitives.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 21:31:53 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/29 22:14:33 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "Fdf.h"

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

t_dot	*create_dot(int x, int y)
{
	t_dot		*dot;

	if (!(dot = (t_dot*)malloc(sizeof(t_dot))))
		return (NULL);
	dot->x = x;
	dot->x = y;
	return (dot);
}

void	free_dot(t_line *line)
{
}

void	free_line(t_dot *dot)
{
}
