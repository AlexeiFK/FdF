/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 21:01:22 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 21:05:17 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_dot
{
	float			x;
	float			y;
	float			z;
	int				row;
	int				color;
	struct s_dot	*next;
}					t_dot;

t_dot	*create_dot(int x, int y, int z, int c);
void	free_dot(t_dot **dot);
t_dot	*ft_reader(char *filename);
void	add_dot(t_dot **dot, t_dot *new);
void	iter_dot(t_dot *dot, void (*f)(t_dot *elem));
t_dot	*ft_cpy(t_dot *dot);

void	shift(t_dot *dot, int x, int y);
void	zoom(t_dot *dot, float mult, int x, int y);
void	zoom_z(t_dot *dot, float mult);
void	conv(t_dot *dot, float angle, int x, int y);
void	net_dot(t_dot *dot, void *param);
void	sh_net_dot(t_dot *dot, void *param, int x, int y);
void	zm_net_dot(void *param, float mult, int x, int y);
void	ag_net_dot(void *param, float angle, int x, int y);
void	draw_line_p(void **param, t_dot *dot1, t_dot *dot2, int color);

#endif
