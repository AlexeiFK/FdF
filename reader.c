/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 19:40:40 by rjeor-mo          #+#    #+#             */
/*   Updated: 2019/08/19 17:23:44 by rjeor-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"
#include "config.h"
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
			tmp = create_dot(x, col,
					ft_atoi(split[x]), strtol((map_color + 1), NULL, 16));
		tmp->row = col;
		add_dot(dots, tmp);
		x++;
	}
	col++;
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

void	free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
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
	while ((ret = get_next_line(fd, &str)) > 0)
	{
		split = ft_strsplit(str, ' ');
		free(str);
		str_to_dots(split, &dots);
		free_split(split);
	}
	if (ret == -1)
		error_file_msg();
	if (color)
		ft_colorize(dots, color);
	return (dots);
}
