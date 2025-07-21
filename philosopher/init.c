/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:06:54 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	cleanup_forks(t_data *data, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
}

int	init_forks(t_data *data)
{
	int	i;

	data->forks = malloc(sizeof(pthread_mutex_t) * data->config.num_philos);
	if (!data->forks)
		return (0);
	i = 0;
	while (i < data->config.num_philos)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
		{
			cleanup_forks(data, i);
			return (0);
		}
		i++;
	}
	if (pthread_mutex_init(&data->print_mutex, NULL) != 0)
	{
		cleanup_forks(data, data->config.num_philos);
		return (0);
	}
	return (1);
}

int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->config.num_philos);
	if (!data->philos)
		return (0);
	i = 0;
	while (i < data->config.num_philos)
	{
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = get_time_ms();
		data->philos[i].meals_eaten = 0;
		data->philos[i].config = &data->config;
		data->philos[i].data = data;
		data->philos[i].left_fork = &data->forks[i];
		if (i == data->config.num_philos - 1)
			data->philos[i].right_fork = &data->forks[0];
		else
			data->philos[i].right_fork = &data->forks[i + 1];
		i++;
	}
	return (1);
}

int	init_data(t_data *data)
{
	data->dead_flag = 0;
	if (!init_forks(data))
		return (0);
	if (!init_philos(data))
		return (0);
	return (1);
}

void	cleanup_data(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->config.num_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mutex);
	free(data->forks);
	free(data->philos);
}
