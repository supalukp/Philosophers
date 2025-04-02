/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:09:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/02 11:44:07 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	set_bool(pthread_mutex_t *mutex, bool *dest, bool value)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	*dest = value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (0);
}

bool	get_bool(pthread_mutex_t *mutex, bool *value)
{
	bool	res;

	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	res = *value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (res);
}

int	set_long(pthread_mutex_t *mutex, long *dest, long value)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	*dest = value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (0);
}

long	get_long(pthread_mutex_t *mutex, long *value)
{
	long	res;

	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	res = *value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (res);
}

bool	check_all_threads_created(t_data *data)
{
	return (get_bool(&data->table_lock, &data->all_philos_created));
}

bool	check_dinner_finished(t_data *data)
{
	return (get_bool(&data->table_lock, &data->end_dinner));
}
