/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 10:09:30 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 14:19:26 by spunyapr         ###   ########.fr       */
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

int	incr_long(pthread_mutex_t *mutex, long *dest, long value)
{
	if (pthread_mutex_lock(mutex) != 0)
		return (1);
	*dest += value;
	if (pthread_mutex_unlock(mutex) != 0)
		return (1);
	return (0);
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
