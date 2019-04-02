/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 23:14:49 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/02 23:23:27 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	iso_conv(t_dot *dot)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
}

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

void	angle_conv(t_dot *dot, double angle)
{
	dot->x = 0;
	dot->y = 0;
	dot->z = 0;
}
