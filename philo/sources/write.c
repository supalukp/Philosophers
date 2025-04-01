/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:24:39 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/01 17:40:47 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void write_status(t_philo *philo, t_status status)
{
    long timestamp;
    bool dinner_finished;
    
    dinner_finished = get_bool(&philo->data->table_lock, &philo->data->end_dinner);
    timestamp = get_current_time(MILLISECOND) - philo->data->start_dinner_time;
    if (philo->full == true)
        return ;
    if (dinner_finished == false)
    {
        if (status == EATING)
            printf("%ld %d is eating", timestamp, philo->id);
        else if (status == SLEEPING) 
            printf("%ld %d is sleeping", timestamp, philo->id);
        else if (status == THINKING)
            printf("%ld %d is thinking", timestamp, philo->id);
        else if (status == TAKE_FORK)
            printf("%ld %d has taken a fork", timestamp, philo->id);
    }
    else
    {
        if (status == DIED)
            printf("%ld %d is died", timestamp, philo->id);
    }
}

int write_mutex_lock(pthread_mutex_t *mutex, t_philo *philo, t_status status)
{
    if (pthread_mutex_lock(mutex) == 1)
        return (1);
    write_status(philo, status);
    if (pthread_mutex_unlock(mutex) == 1)
        return (1);
    return (0);
}
