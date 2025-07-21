/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboussem <aboussem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:06:54 by aboussem          #+#    #+#             */
/*   Updated: 2025/07/06 12:07:00 by aboussem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

// Estructura para la configuración general
typedef struct s_config
{
	int	num_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	must_eat_times;
}	t_config;

// Estructura para cada filósofo
typedef struct s_philo
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long			last_meal;
	int				meals_eaten;
	t_config		*config;
	struct s_data	*data;
}	t_philo;

// Estructura principal del programa
typedef struct s_data
{
	t_config		config;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	int				dead_flag;
}	t_data;

// Funciones principales
int		parse_args(int argc, char **argv, t_config *config);
int		init_data(t_data *data);
void	cleanup_data(t_data *data);
int		init_forks(t_data *data);
int		init_philos(t_data *data);
int		create_threads(t_data *data);
void	join_threads(t_data *data);

// Funciones de utilidad
long	get_time_ms(void);
void	print_status(t_philo *philo, t_data *data, char *status);
void	smart_sleep(long time_ms);

// Funciones de filósofos
void	*philosopher_routine(void *arg);

// Funciones de acciones
int		take_forks(t_philo *philo);
void	release_forks(t_philo *philo);
void	eat(t_philo *philo);
void	think(t_philo *philo);
void	sleep_philo(t_philo *philo);

// Funciones de monitorización
void	*monitor_routine(void *arg);

#endif