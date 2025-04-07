/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:24:19 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/07 15:40:01 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void get_fork(t_philo *philo)
{
    if (philo->id % 2 == 0)
    {
        pthread_mutex_lock(&philo->data->fork[philo->right_folk].fork_lock);
        if (philo->data->fork[philo->right_folk].fork_taken == false)
        {
            write_mutex_lock(philo, TAKE_FORK);
            philo->data->fork[philo->right_folk].fork_taken = true;
        }
        pthread_mutex_lock(&philo->data->fork[philo->left_folk].fork_lock);
        if (philo->data->fork[philo->left_folk].fork_taken == false)
        {
            write_mutex_lock(philo, TAKE_FORK);
            philo->data->fork[philo->left_folk].fork_taken = true;
        }
    }
    else
    {
        pthread_mutex_lock(&philo->data->fork[philo->left_folk].fork_lock);
        if (philo->data->fork[philo->left_folk].fork_taken == false)
        {
            write_mutex_lock(philo, TAKE_FORK);
            philo->data->fork[philo->left_folk].fork_taken = true;
        }
        pthread_mutex_lock(&philo->data->fork[philo->right_folk].fork_lock);
        if (philo->data->fork[philo->right_folk].fork_taken == false)
        {
            write_mutex_lock(philo, TAKE_FORK);
            philo->data->fork[philo->right_folk].fork_taken = true;
        }
    }
}

int eat(t_philo *philo)
{
    get_fork(philo);
    // philo->last_meal_time = get_current_time(MILLISECOND);
    // printf("id %d last meal %ld\n", philo->id, philo->last_meal_time);
    philo->meals_eaten += 1;
    write_mutex_lock(philo, EATING);
    set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time(MILLISECOND));
    philo->last_meal_time = get_current_time(MILLISECOND);
    //printf("id %d last meal %ld in eat\n", philo->id, philo->last_meal_time);
    ft_usleep(philo->data->time_to_eat, philo->data);
    if (philo->data->meal_nbr > 0 && philo->meals_eaten == philo->data->meal_nbr)
        philo->full = true;
    philo->data->fork[philo->right_folk].fork_taken = false;
    philo->data->fork[philo->left_folk].fork_taken = false;
    if (pthread_mutex_unlock(&philo->data->fork[philo->right_folk].fork_lock) != 0)
		return (1);
    if (pthread_mutex_unlock(&philo->data->fork[philo->left_folk].fork_lock) != 0)
        return (1);
    return (0);
}

void philo_sleep(t_philo *philo)
{
    write_mutex_lock(philo, SLEEPING);
    ft_usleep(philo->data->time_to_sleep, philo->data);
}

void think(t_philo *philo)
{
    write_mutex_lock(philo, THINKING);
}