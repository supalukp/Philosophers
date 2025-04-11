/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/11 16:07:52 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philosophers_dining(t_data *data)
{
	int	i;

	i = -1;
	if (data->meal_nbr == 0)
		return (0);
	data->start_dinner_time = get_current_time();
	while (++i < data->philo_nbr)
	{
		if (pthread_create(&data->philo[i].thread_id, NULL, philo_routine,
				&data->philo[i]) != 0)
			return (1);
	}
	if (pthread_create(&data->monitor, NULL, monitor_all_philos, data) != 0)
		return (1);
	set_bool(&data->table_lock, &data->all_philos_created, true);
	i = -1;
	while (++i < data->philo_nbr)
	{
		if (pthread_join(data->philo[i].thread_id, NULL) != 0)
			return (1);
	}
	if (pthread_join(data->monitor, NULL) != 0)
		return (1);
	return (0);
}

static void	one_philo(t_philo *philo)
{
	set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time());
	write_mutex_lock(philo, TAKE_FORK);
	ft_usleep(philo->data->time_to_die, philo->data);
	set_bool(&philo->data->table_lock, &philo->data->end_dinner, true);
	write_mutex_lock(philo, DIED);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->data->philo_nbr == 1)
	{
		one_philo(philo);
		return (NULL);
	}
	set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time());
	incr_long(&philo->data->table_lock, &philo->data->set_all_meal_time, 1);
	wait_set_meal_time(philo);
	if (philo->id % 2 == 0)
	{
		ft_usleep(50, philo->data);
	}
	while (check_dinner_finished(philo->data) != true)
	{
		if (philo->full)
			return (NULL);
		if (eat(philo) != 0)
			return (NULL);
		philo_sleep(philo);
		think(philo);
	}
	return (NULL);
}
