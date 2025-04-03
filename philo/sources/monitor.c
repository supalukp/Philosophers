/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:23:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/03 17:01:46 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void *monitor_all_philos(void *arg)
{
    int i;
    t_data *data;
    bool dead_flag;

    data = (t_data *)arg;
    dead_flag = false;
    while (check_all_threads_created(data) != true);
    while (check_dinner_finished(data) != true)
    {
        i = 0;
        while(i < data->philo_nbr && check_dinner_finished(data) != true)
        {
            dead_flag = philo_dead(&data->philo[i]);
            if (dead_flag == true)
            {
                set_bool(&data->philo[i].philo_lock, &data->philo[i].dead, true);
                set_bool(&data->table_lock, &data->end_dinner, true);
                write_mutex_lock(&data->philo[i], DIED);
            }
            i++;
        }
    }
    return (NULL);
}

bool philo_dead(t_philo *philo)
{
    bool dead_flag;
    long straving_duration;
    long last_meal;
    
    dead_flag = false;
    if (get_bool(&philo->philo_lock, &philo->full) == true)
        return (dead_flag);
    last_meal = get_long(&philo->philo_lock, &philo->last_meal_time);
    printf("last meal = %ld\n", last_meal);
    //pthread_mutex_lock(&philo->philo_lock); 
    straving_duration = get_current_time(MILLISECOND) - last_meal;
    if (straving_duration > philo->data->time_to_die)
        dead_flag = true;
    //pthread_mutex_unlock(&philo->philo_lock);
    return (dead_flag);
}
