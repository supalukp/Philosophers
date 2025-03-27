/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/27 16:18:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	program_init(t_data *data)
{
	data_init(data);
	philos_init(data);
}

void	data_init(t_data *data)
{
	int	i;

	i = 0;
	data->philo = malloc(sizeof(t_philo) * data->philo_nbr);
	if (!data->philo)
		exit_error("Fail Malloc");
	data->fork = malloc(sizeof(t_fork) * data->philo_nbr);
	if (!data->fork)
		exit_error("Fail Malloc");
	data->all_philos_created = false;
	data->end_dinner = false;
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_init(data->fork[i].fork_lock, NULL) != 0)
		{
			data->fork[i].fork_created = false;
			exit_error("Fail create fork");
		}
		else
			data->fork[i].fork_created = true;
		data->fork[i].fork_taken = false;
		i++;
	}
}

void	philos_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		data->philo[i].id = i + 1;
		data->philo[i].meals_eaten = 0;
		data->philo[i].full = false;
		data->philo[i].dead = false;
		if (data->philo[i].id % 2 == 0)
		{
			data->philo[i].right_folk = i;
			data->philo[i].left_folk = i % data->philo_nbr;
		}
		else
		{
			data->philo[i].right_folk = i % data->philo_nbr;
			data->philo[i].left_folk = i;
		}
		data->philo[i].data = data;
		i++;
	}
}
