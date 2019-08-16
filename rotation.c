/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 20:01:02 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/16 20:01:05 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	ox_rot(t_dot *dot, float a)
{
	float	y;
	float	z;
	float	cos_a;
	float	sin_a;

	cos_a = cosf(a);
	sin_a = sinf(a);
	while (dot)
	{
		y = dot->y;
		z = dot->z;
		dot->y = y * cos_a - z * sin_a;
		dot->z = y * sin_a + z * cos_a;
		dot = dot->next;
	}
}

void	oy_rot(t_dot *dot, float a)
{
	float	x;
	float	z;
	float	cos_a;
	float	sin_a;

	cos_a = cosf(a);
	sin_a = sinf(a);
	while (dot)
	{
		x = dot->x;
		z = dot->z;
		dot->x = x * cos_a + z * sin_a;
		dot->z = z * cos_a - x * sin_a;
		dot = dot->next;
	}
}

void	oz_rot(t_dot *dot, float a)
{
	float	x;
	float	y;
	float	cos_a;
	float	sin_a;

	cos_a = cosf(a);
	sin_a = sinf(a);
	while (dot)
	{
		y = dot->y;
		x = dot->x;
		dot->x = x * cos_a - y * sin_a;
		dot->y = x * sin_a + y * cos_a;
		dot = dot->next;
	}
}
