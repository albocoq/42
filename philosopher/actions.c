/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:07:01 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:07:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, philo->data, "has taken a fork");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, philo->data, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, philo->data, "has taken a fork");
		if (philo->left_fork == philo->right_fork)
		{
			pthread_mutex_unlock(philo->left_fork);
			return (0);
		}
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, philo->data, "has taken a fork");
	}
	return (1);
}

void	release_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

void	eat(t_philo *philo)
{
	print_status(philo, philo->data, "is eating");
	philo->last_meal = get_time_ms();
	philo->meals_eaten++;
	smart_sleep(philo->config->time_to_eat);
}

void	think(t_philo *philo)
{
	print_status(philo, philo->data, "is thinking");
}

void	sleep_philo(t_philo *philo)
{
	print_status(philo, philo->data, "is sleeping");
	smart_sleep(philo->config->time_to_sleep);
}
