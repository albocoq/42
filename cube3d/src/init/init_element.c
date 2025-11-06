/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albocoq <albocoq@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 10:44:27 by albocoq           #+#    #+#             */
/*   Updated: 2025/11/05 10:56:00 by albocoq          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

static void	assign_texture(t_elements *elements, char *line, char *tmp)
{
	if (line[0] == 'N' && line[1] == 'O')
	{
		if (elements->no)
			free(elements->no);
		elements->no = tmp;
	}
	else if (line[0] == 'S' && line[1] == 'O')
	{
		if (elements->so)
			free(elements->so);
		elements->so = tmp;
	}
	else if (line[0] == 'W' && line[1] == 'E')
	{
		if (elements->we)
			free(elements->we);
		elements->we = tmp;
	}
	else if (line[0] == 'E' && line[1] == 'A')
	{
		if (elements->ea)
			free(elements->ea);
		elements->ea = tmp;
	}
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
	assign_texture(elements, line, tmp);
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
