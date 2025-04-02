/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/02 14:31:07 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void main_program(t_data *data)
{
    create_philos_threads(data);
}

void create_philos_threads(t_data *data)
{
    int i;

    i = 0;

    while (i < data->philo_nbr)
    {
        pthread_create(&data->philo[i].thread_id, NULL, philo_routine, &data->philo[i]);
        i++;
    }
    data->start_dinner_time = get_current_time(MILLISECOND);
    //printf("start_dinner_time = %ld\n", data->start_dinner_time);
    if (i == data->philo_nbr)
        set_bool(&data->table_lock, &data->all_philos_created, true);
    i = 0;
    while (i < data->philo_nbr)
    {
        pthread_join(data->philo[i].thread_id, NULL);
        i++;
    }
}

void *philo_routine(void *data)
{
    t_philo *philo;

    philo = (t_philo *)data;
   
    while (check_all_threads_created(philo->data) == false);
    //printf("all_thread_is create\n");
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
    //philo->last_meal_time = get_current_time(MILLISECOND);
    //printf("id %d last_meal_time = %ld\n", philo->id, philo->last_meal_time);
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