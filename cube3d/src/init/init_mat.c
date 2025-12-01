/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:51:16 by aboussem          #+#    #+#             */
/*   Updated: 2025/12/01 10:52:44 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pad_existing_rows(t_mat *mat, int new_width)
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

void	init_mat(t_mat *mat, char *line)
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
