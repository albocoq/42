/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:07:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (!parse_args(argc, argv, &data.config))
		return (1);
	if (!init_data(&data))
	{
		printf("Error: Failed to initialize data\n");
		return (1);
	}
	if (!create_threads(&data))
	{
		printf("Error: Failed to create threads\n");
		cleanup_data(&data);
		return (1);
	}
	join_threads(&data);
	cleanup_data(&data);
	return (0);
}
