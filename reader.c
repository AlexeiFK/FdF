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

void	str_to_dots(char **split, t_dot **dots)
{
	static int	col = 0;
	int			x;
	t_dot		*tmp;
	char		*map_color;

	x = 0;
	while (split[x] != NULL)
	{
		map_color = ft_strchr(split[x], ',');
		if (map_color == NULL)
			tmp = create_dot(x, col, ft_atoi(split[x]), BASIC_COLOR);
		else
			tmp = create_dot(x, col, ft_atoi(split[x]), strtol((map_color + 1), NULL, 16));
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

void	ft_paint_dots_up(t_dot *dot, t_colors *c, int start, int end)
{
	int	i;
	t_spec	st_c;
	t_spec	inc;
	t_dot	*tmp;

	i = start;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc(abs(end - start), strtol(c->mid, NULL, 16), strtol(c->top, NULL, 16), &inc);
	while (i <= end)
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
}

void	ft_paint_dots_down(t_dot *dot, t_colors *c, int start, int end)
{
	int	i;
	t_spec	st_c;
	t_spec	inc;
	t_dot	*tmp;

	i = end;
	get_spec(&st_c, strtol(c->mid, NULL, 16));
	get_color_inc(abs(start - end), strtol(c->mid, NULL, 16), strtol(c->bot, NULL, 16), &inc);
	while (i >= start)
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

void	ft_colorize(t_dot *dot, t_colors *c)
{
	int	max;
	int	min;
	int	mid;

	find_max_min(dot, &max, &min);
	mid = (max + min) / 2;
	ft_paint_dots_up(dot, c, mid, max);
	ft_paint_dots_down(dot, c, min, mid);
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

static void	error_file_msg(void)
{
	ft_putstr("File error\n");
	exit(0);
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
	if (fd < 0)
		error_file_msg();
	while (get_next_line(fd, &str) > 0)
	{
		split = ft_strsplit(str, ' ');
		free(str);
		str_to_dots(split, &dots);
		free(split); // normalnii free dlya char**
	}
	if (color)
		ft_colorize(dots, color);
	return (dots);
}
