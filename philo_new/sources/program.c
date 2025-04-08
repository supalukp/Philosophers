/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/08 14:14:05 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void create_philos_threads(t_data *data)
{
    int i;

    i = 0;
    
    data->start_dinner_time = get_current_time(MILLISECOND);
    while (i < data->philo_nbr)
    {
        pthread_create(&data->philo[i].thread_id, NULL, philo_routine, &data->philo[i]);
        i++;
    }
    // set_bool(&data->table_lock, &data->all_philos_created, true);
    // if (data->all_philos_created == true)
    //     printf("all created\n");
    pthread_create(&data->monitor, NULL, monitor_all_philos, data);
    set_bool(&data->table_lock, &data->all_philos_created, true);
    //printf("start_dinner_time = %ld\n\n\n", data->start_dinner_time);
    i = 0;
    while (i < data->philo_nbr)
    {
        pthread_join(data->philo[i].thread_id, NULL);
        i++;
    }
    //set_bool(&data->table_lock, &data->end_dinner, true);
    pthread_join(data->monitor, NULL);
}

void *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    // while (!check_all_threads_created()) // TO DO
    //     ;
    // philo_running++; // TO DO
    if (philo->data->philo_nbr == 1)
    {
        set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
        write_mutex_lock(philo, TAKE_FORK);
        ft_usleep(philo->data->time_to_die, philo->data);
        set_bool(&philo->data->table_lock, &philo->data->end_dinner, true);
        write_mutex_lock(philo, DIED);
        // set_bool(&philo->data->table_lock, &philo->data->end_dinner, true);
        // while (check_dinner_finished(philo->data) != true);
        return (NULL);
    }
    //philo->last_meal_time = get_current_time(MILLISECOND);
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
    //printf("here id %d last meal = %ld\n", philo->id,philo->last_meal_time);
    set_long(&philo->data->table_lock, &philo->data->set_meal_time, philo->data->set_meal_time + 1);
    while (get_long(&philo->data->table_lock, &philo->data->set_meal_time) != philo->data->philo_nbr)
    // {
    //     usleep(500);
    // }
    while (check_dinner_finished(philo->data) != true)
    {
        if (philo->full == true)
            break;
        if (eat(philo) != 0)
            return (NULL);
        philo_sleep(philo);
        think(philo);
    }
    return (NULL);
}
