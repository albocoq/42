/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:06:54 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*philosopher_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (!philo->data->dead_flag)
	{
		if (!take_forks(philo))
			break ;
		eat(philo);
		release_forks(philo);
		if (philo->config->must_eat_times > 0
			&& philo->meals_eaten >= philo->config->must_eat_times)
			break ;
		think(philo);
		sleep_philo(philo);
	}
	return (NULL);
}
