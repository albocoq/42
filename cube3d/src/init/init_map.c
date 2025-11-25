/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:47:57 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/25 12:17:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_rgba_bg(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return (((int)r << 0) | ((int)g << 8) | ((int)b << 16) | (int)(a << 24));
}

static void	pad_existing_rows(t_mat *mat, int new_width)
{
	int			i;
	size_t		old_len;
	char		*newrow;

	i = 0;
	while (i < mat->height)
	{
		old_len = ft_strlen(mat->mat[i]);
		if ((int)old_len < new_width)
		{
			newrow = (char *)malloc(new_width + 1);
			if (!newrow)
				return ;
			ft_memcpy(newrow, mat->mat[i], old_len);
			ft_memset(newrow + old_len, ' ', new_width - (int)old_len);
			newrow[new_width] = '\0';
			free(mat->mat[i]);
			mat->mat[i] = newrow;
		}
		i++;
	}
}

static void	init_mat(t_mat *mat, char *line)
{
	size_t		linelen;
	int			new_width;

	linelen = line_len_no_nl(line);
	if ((int)linelen > mat->width)
	{
		new_width = (int)linelen;
		pad_existing_rows(mat, new_width);
		mat->width = new_width;
	}
	if (mat->height == 0)
		mat->height = 1;
	else
		mat->height++;
	mat->mat = ft_realloc(mat->mat, sizeof(char *) * (mat->height + 1));
	mat->mat[mat->height - 1] = (char *)malloc(mat->width + 1);
	if (mat->mat[mat->height - 1])
	{
		ft_memcpy(mat->mat[mat->height - 1], line, linelen);
		if (linelen < (size_t)mat->width)
			ft_memset(mat->mat[mat->height - 1] + linelen, ' ',
				mat->width - (int)linelen);
		mat->mat[mat->height - 1][mat->width] = '\0';
	}
	mat->mat[mat->height] = NULL;
}

static int	process_line(t_map *map, char *line)
{
	int	res;

	if (only_whitespace(line))
		return (0);
	res = init_elements(&map->elements, line);
	if (res == 2)
		return (2);
	if (!res)
		return (0);
	init_mat(&map->mat, line);
	return (1);
}

int	init_map(t_map *map, int fd)
{
	char	*line;
	int		res;

	line = get_next_line(fd);
	init_textures(map);
	while (line != NULL)
	{
		res = process_line(map, line);
		if (res == 2)
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
