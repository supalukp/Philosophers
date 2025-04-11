/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 11:24:19 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/11 16:12:43 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	get_fork(t_philo *philo)
{
	int	first_f;
	int	second_f;

	first_f = philo->right_fork;
	second_f = philo->left_fork;
	if (philo->id % 2 == 0)
	{
		first_f = philo->left_fork;
		second_f = philo->right_fork;
	}
	if (pthread_mutex_lock(&philo->data->fork[first_f].fork_lock))
		return (1);
	if (philo->data->fork[first_f].fork_taken == false)
	{
		write_mutex_lock(philo, TAKE_FORK);
		philo->data->fork[first_f].fork_taken = true;
	}
	if (pthread_mutex_lock(&philo->data->fork[second_f].fork_lock))
		return (1);
	if (philo->data->fork[second_f].fork_taken == false)
	{
		write_mutex_lock(philo, TAKE_FORK);
		philo->data->fork[second_f].fork_taken = true;
	}
	return (0);
}

static int	release_fork(t_philo *philo)
{
	int	first_f;
	int	second_f;

	first_f = philo->right_fork;
	second_f = philo->left_fork;
	philo->data->fork[first_f].fork_taken = false;
	if (pthread_mutex_unlock(&philo->data->fork[first_f].fork_lock) != 0)
		return (1);
	philo->data->fork[second_f].fork_taken = false;
	if (pthread_mutex_unlock(&philo->data->fork[second_f].fork_lock) != 0)
		return (1);
	return (0);
}

int	eat(t_philo *philo)
{
	if (get_fork(philo))
		return (1);
	philo->meals_eaten += 1;
	write_mutex_lock(philo, EATING);
	set_long(&philo->philo_lock, &philo->last_meal_time, get_current_time());
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->meal_nbr > 0
		&& philo->meals_eaten == philo->data->meal_nbr)
	{
		set_bool(&philo->philo_lock, &philo->full, true);
		incr_long(&philo->data->table_lock, &philo->data->count_philo_full, 1);
	}
	if (release_fork(philo))
		return (1);
	return (0);
}

void	philo_sleep(t_philo *philo)
{
	write_mutex_lock(philo, SLEEPING);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}

void	think(t_philo *philo)
{
	long	think_time;

	write_mutex_lock(philo, THINKING);
	if (philo->data->philo_nbr % 2 == 0)
		return ;
	think_time = philo->data->time_to_eat * 2 - philo->data->time_to_sleep;
	if (think_time < 0)
		think_time = 0;
	ft_usleep(think_time * 0.5, philo->data);
}
