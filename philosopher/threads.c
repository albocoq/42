/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:07:01 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:07:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_threads(t_data *data)
{
	int			i;
	pthread_t	monitor;

	i = 0;
	while (i < data->config.num_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL,
				philosopher_routine, &data->philos[i]) != 0)
			return (0);
		i++;
	}
	if (pthread_create(&monitor, NULL, monitor_routine, data) != 0)
		return (0);
	if (pthread_join(monitor, NULL) != 0)
		return (0);
	return (1);
}

void	join_threads(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.num_philos)
	{
		pthread_join(data->philos[i].thread, NULL);
		i++;
	}
}
