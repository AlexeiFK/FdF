/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/04/04 19:37:28 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "fdf.h"
#include "get_next_line.h"

void		get_color_inc_o(int n_pixels, unsigned int color1, unsigned int color2, t_spec *inc)
{
	t_spec	s1;
	t_spec	s2;

	s1.r = (color1 & 0xff0000) >> 16;
	s1.g = (color1 & 0x00ff00) >> 8;
	s1.b = (color1 & 0x0000ff);
	s2.r = (color2 & 0xff0000) >> 16;
	s2.g = (color2 & 0x00ff00) >> 8;
	s2.b = (color2 & 0x0000ff);
	inc->r = ((s2.r - s1.r) / n_pixels);
	inc->g = ((s2.g - s1.g) / n_pixels);
	inc->b = ((s2.b - s1.b) / n_pixels);
}

void	str_to_dots(char **split, t_dot **dots)// t_colors *c)
{
	static int	col = 0;
	int			x;
	int			i;
	t_dot		*tmp;
	int		color_flag;

	x = 0;
	/*
	if (c == NULL)
		color_flag = 0;
	else
		color_flag = 1;
		*/
	while (split[x] != NULL)
	{/*
		if (color_flag)
		{
			if (ft_atoi(split[x]) == 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->mid, NULL, 16));
			else if (ft_atoi(split[x]) > 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->top, NULL, 16));
			else if (ft_atoi(split[x]) < 0)
				tmp = create_dot(x, col, ft_atoi(split[x]), strtol(c->bot, NULL, 16));
		}
		else
		*/
			tmp = create_dot(x, col, ft_atoi(split[x]), 0xFFFFFF);
		tmp->row = col;
		add_dot(dots, tmp);
		x++;
	}
	col++;
}

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

void	ft_colorize(t_dot *dot, t_colors *c)
{
	int	max;
	int	min;
	int	mid;
	int	i;
	t_dot	*tmp;
	t_spec	st_c;
	t_spec  inc;

	find_max_min(dot, &max, &min);
	mid = (max + min) / 2;
	i = mid;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc_o(abs(max - mid), strtol(c->mid, NULL, 16), strtol(c->top, NULL, 16), &inc);
	while (i <= max)
	{
		tmp = dot;
		while (tmp)
		{
			if (tmp->z == i)
				tmp->color = (((int)st_c.r << 16) | ((int)st_c.g << 8) | (int)st_c.b);
			tmp = tmp->next;
		}
		i++;
		inc_st_color(&st_c, &inc);
	}
	i = mid;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc_o(abs(min - mid), strtol(c->mid, NULL, 16), strtol(c->bot, NULL, 16), &inc);
	while (i >= min)
	{
		tmp = dot;
		while (tmp)
		{
			if (tmp->z == i)
				tmp->color = (((int)st_c.r << 16) | ((int)st_c.g << 8) | (int)st_c.b);
			tmp = tmp->next;
		}
		i--;
		inc_st_color(&st_c, &inc);
	}
}

void	ft_cpy(t_dot **new, t_dot *dot)
{
	t_dot	*tmp;

	while (dot)
	{
		tmp = create_dot(dot->x, dot->y, dot->z, dot->color);
		tmp->row = dot->row;
		add_dot(new, tmp);
		dot = dot->next;
	}
}

t_dot	*ft_reader(char *filename, t_colors *color)
{
	int		fd;
	char	*str;
	char	**split;
	int		ret;
	t_dot	*dots;

	dots = NULL;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &str) > 0)
	{
		split = ft_strsplit(str, ' ');
		free(str);
		str_to_dots(split, &dots);
		free(split); // normalnii free dlya char**
	}
	ft_colorize(dots, color);
	return (dots);
}
