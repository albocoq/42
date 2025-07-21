/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:07:01 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:07:01 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}

static int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

static int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong number of arguments\n");
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_valid_number(argv[i]))
		{
			printf("Error: All arguments must be positive integers\n");
			return (0);
		}
		i++;
	}
	return (1);
}

static int	parse_values(int argc, char **argv, t_config *config)
{
	config->num_philos = ft_atoi(argv[1]);
	config->time_to_die = ft_atoi(argv[2]);
	config->time_to_eat = ft_atoi(argv[3]);
	config->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		config->must_eat_times = ft_atoi(argv[5]);
	else
		config->must_eat_times = -1;
	if (config->num_philos <= 0 || config->time_to_die <= 0
		|| config->time_to_eat <= 0 || config->time_to_sleep <= 0
		|| (argc == 6 && config->must_eat_times <= 0))
	{
		printf("Error: All arguments must be positive integers\n");
		return (0);
	}
	return (1);
}

int	parse_args(int argc, char **argv, t_config *config)
{
	if (!validate_args(argc, argv))
		return (0);
	if (!parse_values(argc, argv, config))
		return (0);
	return (1);
}
