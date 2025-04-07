/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/07 16:16:33 by spunyapr         ###   ########.fr       */
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
    set_bool(&data->table_lock, &data->all_philos_created, true);
    // if (data->all_philos_created == true)
    //     printf("all created\n");
    pthread_create(&data->monitor, NULL, monitor_all_philos, data);
    //printf("start_dinner_time = %ld\n\n\n", data->start_dinner_time);
    i = 0;
    while (i < data->philo_nbr)
    {
        pthread_join(data->philo[i].thread_id, NULL);
        i++;
    }
    pthread_join(data->monitor, NULL);
}

void *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
    while (check_all_threads_created(philo->data) != true);
    if (philo->data->philo_nbr == 1)
    {
        set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
        write_mutex_lock(philo, TAKE_FORK);
        // ft_usleep(philo->data->time_to_die, philo->data);
        // //while (check_dinner_finished(philo->data) != true);
        return (NULL);
    }
    //philo->last_meal_time = get_current_time(MILLISECOND);
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
    //printf("here id %d last meal = %ld\n", philo->id,philo->last_meal_time);
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
