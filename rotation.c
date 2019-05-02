
#include "fdf.h"
#include <math.h>

void	ox_rot(t_dot *dot, float a)
{
	float y;
	float z;

	while (dot)
	{
		y = dot->y;
		z = dot->z;
		dot->y = y * cosf(a) - z * sinf(a);
		dot->z = y * sinf(a) + z * cosf(a);
		dot = dot->next;
	}
}

void	oy_rot(t_dot *dot, float a)
{
	float	x;
	float	z;

	while (dot)
	{
		x = dot->x;
		z = dot->z;
		dot->x = x * cosf(a) + z * sinf(a);
		dot->z = z * cosf(a) - x * sinf(a);
		dot = dot->next;
	}
}

void	oz_rot(t_dot *dot, float a)
{
	float	x;
	float	y;
	while (dot)
	{
		y = dot->y;
		x = dot->x;
		dot->x = x * cosf(a) - y * sinf(a);
		dot->y = x * sinf(a) + y * cosf(a);
		dot = dot->next;
	}
}
