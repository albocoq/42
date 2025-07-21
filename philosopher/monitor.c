/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:06:54 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_death(t_philo *philo)
{
	long	current_time;
	long	time_since_last_meal;

	current_time = get_time_ms();
	time_since_last_meal = current_time - philo->last_meal;
	if (time_since_last_meal >= philo->config->time_to_die)
	{
		print_status(philo, philo->data, "died");
		philo->data->dead_flag = 1;
		return (1);
	}
	return (0);
}

static int	check_all_meals(t_data *data)
{
	int	i;

	if (data->config.must_eat_times <= 0)
		return (0);
	i = 0;
	while (i < data->config.num_philos)
	{
		if (data->philos[i].meals_eaten < data->config.must_eat_times)
			return (0);
		i++;
	}
	return (1);
}

void	*monitor_routine(void *arg)
{
	t_data	*data;
	int		i;

	data = (t_data *)arg;
	while (1)
	{
		i = 0;
		while (i < data->config.num_philos)
		{
			if (check_death(&data->philos[i]))
				return (NULL);
			i++;
		}
		if (check_all_meals(data))
		{
			data->dead_flag = 1;
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}
