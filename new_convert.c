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


void	conic_conv(t_dot *dot)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
}

void	paral_conv(t_dot *dot)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
}

void	angle_conv(t_dot *dot, double angle_x, double angle_y,
		double angle_z)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
}

void	conv(t_dot *dot, float angle, int by_x, int by_y)
{
	float	x;
	float	y;

	while (dot)
	{
		x = dot->x - by_x;
		y = dot->y - by_y;
		dot->x = x * cosf(angle) - y * sinf(angle); //hypot(x, y) * cos(angle);
		dot->y = x * sinf(angle) + y * cosf(angle);//hypot(x, y) * sin(angle);
		dot = dot->next;
	}
}

void	iso_conv(t_dot *dot)
{
	float a = asin(tan(M_PI / 6));
	float b = M_PI / 4;

	float x = dot->x;
	float y = dot->y;
	float z = dot->z;
	printf("a = %f\n", a);
	printf("b = %f\n", b);
	printf("x = %f\n", x);
	printf("y = %f\n", y);
	printf("z = %f\n", z);

	while (dot)
	{
		x = dot->x;
		y = dot->y;
		z = dot->z;
		dot->y = y * cosf(a) - z * sinf(a);
		dot->z = y * sinf(a) + z * cosf(a);
	

		z = dot->z;
		dot->x = x * cosf(b) - z * sinf(b);
		dot->z = (-1) * x * sinf(b) + z * cosf(b);
		dot = dot->next;
	}
}

void	zoom_z(t_dot *dot, float mult)
{
	while (dot)
	{
		dot->x = dot->x * mult;
		dot->y = dot->y * mult;
		dot->z = dot->z;
		dot = dot->next;
	}
}
void	zoom(t_dot *dot, float mult, int x, int y)
{
	float		res1;
	float		res2;

	while (dot)
	{
		dot->z = dot->z * mult; //
		res1 = (dot->x - x)	* mult;
		res2 = (dot->y - y)	* mult;
		dot->x = x + res1;
		dot->y = y + res2;
		dot = dot->next;
	}
}
void	shift(t_dot *dot, int x, int y)
{
	while (dot)
	{
		dot->x += x;
		dot->y += y;
		dot = dot->next;
	}
}
