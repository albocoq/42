/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:44:27 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/18 13:54:33 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	assign_texture(t_elements *elements, char *line, char *tmp)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (elements->no)
			return (printf("Error: Duplicate key NO founded\n"), 1);
		elements->no = tmp;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (elements->so)
			return (printf("Error: Duplicate key SO founded\n"), 1);
		elements->so = tmp;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (elements->we)
			return (printf("Error: Duplicate key WE founded\n"), 1);
		elements->we = tmp;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (elements->ea)
			return (printf("Error: Duplicate key EA founded\n"), 1);
		elements->ea = tmp;
	}
	return (0);
}

static int	handle_texture(t_elements *elements, char *line)
{
	const char	*p;
	char		*tmp;

	p = line + 2;
	while (*p == ' ' || *p == '\t')
		p++;
	tmp = dup_trim_ws(p);
	if (!tmp)
		return (0);
	if (assign_texture(elements, line, tmp) != 0)
		return (2);
	return (0);
}

static int	handle_color(t_elements *elements, char *line)
{
	const char	*p;
	char		*tmp;

	p = line + 1;
	while (*p == ' ' || *p == '\t')
		p++;
	tmp = dup_trim_ws(p);
	if (!tmp)
		return (0);
	if (line[0] == 'F')
	{
		if (elements->f)
			free(elements->f);
		elements->f = tmp;
	}
	else
	{
		if (elements->c)
			free(elements->c);
		elements->c = tmp;
	}
	return (0);
}

int	init_elements(t_elements *elements, char *line)
{
	if ((line[0] == 'N' && line[1] == 'O')
		|| (line[0] == 'S' && line[1] == 'O')
		|| (line[0] == 'W' && line[1] == 'E')
		|| (line[0] == 'E' && line[1] == 'A'))
		return (handle_texture(elements, line));
	else if (line[0] == 'F' || line[0] == 'C')
		return (handle_color(elements, line));
	return (1);
}
