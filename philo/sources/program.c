/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/09 22:52:38 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void philosophers_dining(t_data *data)
{
    int i;

    i = 0;
    
    data->start_dinner_time = get_current_time();
    while (i < data->philo_nbr)
    {
        pthread_create(&data->philo[i].thread_id, NULL, philo_routine, &data->philo[i]);
        i++;
    }
    pthread_create(&data->monitor, NULL, monitor_all_philos, data);
    set_bool(&data->table_lock, &data->all_philos_created, true);
    i = 0;
    while (i < data->philo_nbr)
    {
        pthread_join(data->philo[i].thread_id, NULL);
        i++;
    }
    pthread_join(data->monitor, NULL);
}

void one_philo(t_philo *philo)
{
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time());
    write_mutex_lock(philo, TAKE_FORK);
    ft_usleep(philo->data->time_to_die, philo->data);
    set_bool(&philo->data->table_lock, &philo->data->end_dinner, true);
    write_mutex_lock(philo, DIED);
}

void *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    
    //incr_long(&philo->data->table_lock, &philo->data->threads_running, 1);
    if (philo->data->philo_nbr == 1)
    {
        one_philo(philo);
        return (NULL);
    }
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time());
    incr_long(&philo->data->table_lock, &philo->data->set_meal_time, 1);
    //while (get_long(&philo->data->table_lock, &philo->data->set_meal_time) != philo->data->philo_nbr);
    wait_set_meal_time(philo);
    while (check_dinner_finished(philo->data) != true && philo->full != true)
    {
        if (eat(philo) != 0)
            return (NULL);
        philo_sleep(philo);
        think(philo);
    }
    return (NULL);
}
