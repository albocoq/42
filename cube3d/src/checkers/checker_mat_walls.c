/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_mat_walls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:02:27 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 11:12:52 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_space_or_empty(char c)
{
	return (c == ' ' || c == '\0' || c == '\n');
}

int	check_top_walls(t_mat *mat, int i, int j)
{
	char	c;

	while (j < mat->width)
	{
		c = mat->mat[0][j];
		if (c == ' ' || c == '\0')
		{
			i = 0;
			while (i < mat->height && is_space_or_empty(mat->mat[i][j]))
				i++;
			if (i >= mat->height || mat->mat[i][j] != '1')
			{
				printf("Error: Top row is not properly walled.\n");
				return (1);
			}
		}
		else if (c != '1' && c != '\n')
		{
			printf("Error: Top row is not properly walled.\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_bottom_walls(t_mat *mat, int i, int j)
{
	char	c;

	while (j < mat->width)
	{
		c = mat->mat[mat->height - 1][j];
		if (c == ' ' || c == '\0')
		{
			i = mat->height - 1;
			while (i >= 0 && is_space_or_empty(mat->mat[i][j]))
				i--;
			if (i < 0 || mat->mat[i][j] != '1')
			{
				printf("Error: Bottom row is not properly walled.\n");
				return (1);
			}
		}
		else if (c != '1' && c != '\n')
		{
			printf("Error: Bottom row is not properly walled.\n");
			return (1);
		}
		j++;
	}
	return (0);
}

int	check_left_walls(t_mat *mat, int i, int j)
{
	char	c;

	while (i < mat->height)
	{
		c = mat->mat[i][0];
		if (c == ' ' || c == '\0')
		{
			j = 0;
			while (j < mat->width && is_space_or_empty(mat->mat[i][j]))
				j++;
			if (j >= mat->width || mat->mat[i][j] != '1')
			{
				printf("Error: Left column is not properly walled.\n");
				return (1);
			}
		}
		else if (c != '1' && c != '\n')
		{
			printf("Error: Left column is not properly walled.\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_right_walls(t_mat *mat, int i, int j)
{
	char	c;

	while (i < mat->height)
	{
		c = mat->mat[i][mat->width - 1];
		if (c == ' ' || c == '\0')
		{
			j = mat->width - 1;
			while (j >= 0 && is_space_or_empty(mat->mat[i][j]))
				j--;
			if (j < 0 || mat->mat[i][j] != '1')
			{
				printf("Error: Right column is not properly walled.\n");
				return (1);
			}
		}
		else if (c != '1' && c != '\n')
		{
			printf("Error: Right column is not properly walled.\n");
			return (1);
		}
		i++;
	}
	return (0);
}
