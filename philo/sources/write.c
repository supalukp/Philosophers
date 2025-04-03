/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:24:39 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/03 11:18:16 by spunyapr         ###   ########.fr       */
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
            printf("%ld %d is eating -------------------------on meal %ld\n", timestamp, philo->id, philo->meals_eaten);
        else if (status == SLEEPING) 
            printf("%ld %d is sleeping\n", timestamp, philo->id);
        else if (status == THINKING)
            printf("%ld %d is thinking\n", timestamp, philo->id);
        else if (status == TAKE_FORK_LEFT)
            printf("%ld %d has taken a left fork   no.%d\n", timestamp, philo->id,philo->left_folk);
        else if (status == TAKE_FORK_RIGHT)
            printf("%ld %d has taken a right fork  no.%d\n", timestamp, philo->id,philo->right_folk);
    }
    else
    {
        if (status == DIED)
            printf("%ld %d is died\n", timestamp, philo->id);
    }
}

int write_mutex_lock(t_philo *philo, t_status status)
{
    if (pthread_mutex_lock(&philo->data->write_lock) == 1)
        return (1);
    write_status(philo, status);
    if (pthread_mutex_unlock(&philo->data->write_lock) == 1)
        return (1);
    return (0);
}
