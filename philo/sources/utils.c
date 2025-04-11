/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:24:01 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 13:32:19 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	return_error(const char *error_msg)
{
	printf("%s", error_msg);
	return (1);
}

long	get_current_time(void)
{
	struct timeval	tv;
	long			current_time;

	if (gettimeofday(&tv, NULL) == -1)
		return_error("gettimeofday failed\n");
	current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	return (current_time);
}

void	ft_usleep(long duration, t_data *data)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < duration)
	{
		if (check_dinner_finished(data) == true)
			break ;
		usleep(100);
	}
}

int	destroy_and_free(t_data *data)
{
	int	i;

	i = 0;
	if (pthread_mutex_destroy(&data->write_lock) != 0)
		return (return_error("write_lock mutex destroy failed\n"));
	if (pthread_mutex_destroy(&data->table_lock) != 0)
		return (return_error("table_lock mutex destroy failed\n"));
	while (i < data->philo_nbr)
	{
		if (pthread_mutex_destroy(&data->fork[i].fork_lock) != 0)
			return (return_error("fork mutex destroy failed\n"));
		if (pthread_mutex_destroy(&data->philo[i].philo_lock) != 0)
			return (return_error("philo mutex destroy failed\n"));
		i++;
	}
	if (data->philo)
		free(data->philo);
	if (data->fork)
		free(data->fork);
	return (0);
}
