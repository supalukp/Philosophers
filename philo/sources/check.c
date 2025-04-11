/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:32:48 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/11 16:07:22 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	wait_set_meal_time(t_philo *philo)
{
	while (get_long(&philo->data->table_lock,
			&philo->data->set_all_meal_time) != philo->data->philo_nbr)
	{
		usleep(100);
	}
}

bool	check_all_threads_created(t_data *data)
{
	return (get_bool(&data->table_lock, &data->all_philos_created));
}

bool	check_dinner_finished(t_data *data)
{
	return (get_bool(&data->table_lock, &data->end_dinner));
}
