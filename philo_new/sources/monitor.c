/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 11:23:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/08 14:16:15 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

// void create_monitor_threads(t_data *data)
// {
//     pthread_create(&data->monitor, NULL, monitor_all_philos, &data);
// }

void *monitor_all_philos(void *arg)
{
    int i;
    int count;
    t_data *data;

    data = (t_data *)arg;
    count = 0;
    if (data->philo_nbr == 1)
        return (NULL);
    while (check_all_threads_created(data) != true);
    //usleep(2000);
    // while (!philo_running)//TODO
    //     ;
    while (get_long(&data->table_lock, &data->set_meal_time) != data->philo_nbr);
    while (check_dinner_finished(data) != true)
    {
        // if (get_long(&data->table_lock, &data->all_full) == data->philo_nbr)
        // {
        //     set_bool(&data->table_lock, &data->end_dinner, true);
        //     break;
        // }
        // if (philo_full(data) == true)
        // {
        //     count++;
        //     if (count == data->meal_nbr)
        //     {
        //         set_bool(&data->table_lock, &data->end_dinner, true);
        //         break;
        //     }
        // }
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
        //usleep(2000);
    }
    return (NULL);
}

bool philo_dead(t_philo *philo)
{
    long straving_duration;
    
    if (get_bool(&philo->philo_lock, &philo->full))
        return (false);
    //printf("no.%d lst meal = %ld\n",philo->id, get_long(&philo->philo_lock, &philo->last_meal_time));
    straving_duration = get_current_time(MILLISECOND) - get_long(&philo->philo_lock, &philo->last_meal_time);
    //printf("no.%d strving = %ld\n",philo->id, straving_duration);
    if (straving_duration > (philo->data->time_to_die))
        return (true);
    return (false);
}

bool philo_full(t_data *data)
{
    int i;
    
    i = 0;
    if (check_dinner_finished(data) == true)
        return (false);
    if (get_bool(&data->philo[i].philo_lock, &data->philo[i].full))
        return (true);
    return (false);
}

void flag_dead(t_data *data)
{
    int i;
    
    i = 0;
    while(i < data->philo_nbr)
    {
        if (check_dinner_finished(data) == true)
            break;
        if (philo_dead(&data->philo[i]) == true)
        {
            set_bool(&data->philo[i].philo_lock, &data->philo[i].dead, true);
            set_bool(&data->table_lock, &data->end_dinner, true);
            write_mutex_lock(&data->philo[i], DIED);
            break;
        }
        i++;
    }
}
