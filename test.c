/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 18:34:38 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/03/29 19:40:37 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void		count(int x, int y, int endx, int endy)
{
	float	inc_x = 1;
	float	inc_y = 1;
	int		flagx = 1;
	int		flagy = 1;
	float		dif_x;
	float		dif_y;
	float		dif_max;
	int			i = 0;


	if (x > endx)
		flagx = -1;
	if (y > endy)
		flagy = -1;
	dif_x = abs(endx - x);
	dif_y = abs(endy - y);
	printf("dif_x = %f dif_y = %f\n", dif_x, dif_y);
	if (dif_y > dif_x)
	{
		inc_x = (dif_x / dif_y);
		dif_max = fabsf(dif_y);
	}
	else if (dif_x >= dif_y)
	{
		inc_y = (dif_y / dif_x);
		dif_max = fabsf(dif_x);
	}
	inc_x = inc_x * flagx;
	inc_y = inc_y * flagy;
	printf("inc_x = %f inc_y = %f\n", inc_x, inc_y);
	dif_x = x;
	dif_y = y;
	while (i <= dif_max)
	{
		printf("putpixel in (%d,%d)\n", (int)round(dif_x), (int)round(dif_y));
		dif_x += inc_x;
		dif_y += inc_y;
		i++;
	}
}





int			main()
{
	int x;
	int	y;

	int endx;
	int	endy;

	x = 0;
	y = 0;

	endx = 10;
	endy = 20;

	count(x, y, endx, endy);

	count(20, 35, 100, 233);
//
//	count(100, 100, 200, 200);


	count(20, 35, 400, 100);





	return (0);
}
