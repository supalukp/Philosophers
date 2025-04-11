/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:23:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 14:52:04 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static bool	philo_dead(t_philo *philo)
{
	long	straving_duration;

	if (get_bool(&philo->philo_lock, &philo->full))
		return (false);
	straving_duration = get_current_time() - get_long(&philo->philo_lock,
			&philo->last_meal_time);
	if (straving_duration > (philo->data->time_to_die))
	{
		set_bool(&philo->philo_lock, &philo->dead, true);
		set_bool(&philo->data->table_lock, &philo->data->end_dinner, true);
		write_mutex_lock(philo, DIED);
		return (true);
	}
	return (false);
}

void	*monitor_all_philos(void *arg)
{
	int		i;
	t_data	*data;

	data = (t_data *)arg;
	if (data->philo_nbr == 1)
		return (NULL);
	wait_set_meal_time(data->philo);
	while (check_dinner_finished(data) != true)
	{
		if (get_long(&data->table_lock, &data->all_full) == data->philo_nbr)
		{
			set_bool(&data->table_lock, &data->end_dinner, true);
			return (NULL);
		}
		i = 0;
		while (i < data->philo_nbr)
		{
			if (philo_dead(&data->philo[i]) == true)
				return (NULL);
			i++;
		}
	}
	return (NULL);
}
