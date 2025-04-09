/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:23:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/09 22:39:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *monitor_all_philos(void *arg)
{
    int i;
    t_data *data;

    data = (t_data *)arg;
    if (data->philo_nbr == 1)
        return (NULL);
    // while (check_all_threads_created(data) != true);
    // while (get_long(&data->table_lock, &data->threads_running) != data->philo_nbr);
    while (get_long(&data->table_lock, &data->set_meal_time) != data->philo_nbr);
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
            {
                set_bool(&data->philo[i].philo_lock, &data->philo[i].dead, true);
                set_bool(&data->table_lock, &data->end_dinner, true);
                write_mutex_lock(&data->philo[i], DIED);
                return (NULL);
            }
            i++;
        }
    }
    return (NULL);
}

bool philo_dead(t_philo *philo)
{
    long straving_duration;
    
    if (get_bool(&philo->philo_lock, &philo->full))
        return (false);
    straving_duration = get_current_time() - get_long(&philo->philo_lock, &philo->last_meal_time);
    if (straving_duration > (philo->data->time_to_die))
        return (true);
    return (false);
}

