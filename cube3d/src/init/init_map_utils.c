/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:51:16 by aboussem          #+#    #+#             */
/*   Updated: 2025/12/01 13:15:00 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	process_map_line(t_map *map, char *line)
{
	int	res;

	res = process_line(map, line);
	if (res == 2)
		return (1);
	return (0);
}
