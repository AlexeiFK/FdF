/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:14:49 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 21:21:59 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	zoom_z(t_dot *dot, float mult, float multz)
{
	while (dot)
	{
		dot->x = dot->x * mult;
		dot->y = dot->y * mult;
		dot->z = dot->z * multz;
		dot = dot->next;
	}
}

void	zoom(t_dot *dot, float mult, int x, int y)
{
	float		res1;
	float		res2;

	while (dot)
	{
		dot->z = dot->z * mult;
		res1 = (dot->x - x) * mult;
		res2 = (dot->y - y) * mult;
		dot->x = x + res1;
		dot->y = y + res2;
		dot = dot->next;
	}
}
void	shift(t_dot *dot, int x, int y, int z)
{
	while (dot)
	{
		dot->x += x;
		dot->y += y;
		dot->z += z;
		dot = dot->next;
	}
}
