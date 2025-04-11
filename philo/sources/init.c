/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 15:00:08 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	first_init(t_data *data)
{
	data->philo = NULL;
	data->fork = NULL;
	data->all_philos_created = false;
	data->threads_running = 0;
	data->start_dinner_time = -1;
	data->end_dinner = false;
	data->set_meal_time = 0;
	data->all_full = 0;
}

static int	data_init(t_data *data)
{
	data->philo = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philo)
		return (return_error("Fail Malloc\n"));
	data->fork = malloc(sizeof(t_fork) * data->philo_nbr);
	if (!data->fork)
	{
		free(data->philo);
		return (return_error("Fail Malloc\n"));
	}
	return (0);
}

static int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&data->write_lock, NULL) != 0)
		return (return_error("Fail create mutex write lock\n"));
	if (pthread_mutex_init(&data->table_lock, NULL) != 0)
		return (return_error("Fail create mutex table lock\n"));
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_init(&data->philo[i].philo_lock, NULL) != 0)
			return (return_error("Fail create mutex philo lock\n"));
		if (pthread_mutex_init(&data->fork[i].fork_lock, NULL) != 0)
		{
			data->fork[i].fork_created = false;
			return (return_error("Fail create fork lock\n"));
		}
		else
			data->fork[i].fork_created = true;
		data->fork[i].fork_taken = false;
		i++;
	}
	return (0);
}

static int	philos_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].full = false;
		data->philo[i].dead = false;
		data->philo[i].right_fork = data->philo[i].id % data->philo_nbr;
		data->philo[i].left_fork = data->philo[i].id - 1;
		data->philo[i].data = data;
		i++;
	}
	return (0);
}

int	program_init(t_data *data)
{
	first_init(data);
	if (data_init(data) == 1)
		return (1);
	if (philos_init(data) == 1)
		return (1);
	if (mutex_init(data) == 1)
		return (1);
	return (0);
}
