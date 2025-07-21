/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:06:54 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_time_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	print_status(t_philo *philo, t_data *data, char *status)
{
	long	timestamp;

	timestamp = get_time_ms();
	pthread_mutex_lock(&data->print_mutex);
	printf("%ld %d %s\n", timestamp, philo->id, status);
	pthread_mutex_unlock(&data->print_mutex);
}

void	smart_sleep(long time_ms)
{
	long	start;

	start = get_time_ms();
	while (get_time_ms() - start < time_ms)
		usleep(100);
}
