/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:24:01 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/02 12:54:51 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	return_error(const char *error_msg)
{
	printf("%s\n", error_msg);
	return (1);
}

long	get_current_time(t_time time)
{
	struct timeval	tv;
	long current_time;

	current_time = 0;
	if (gettimeofday(&tv, NULL) == -1)
		return_error("gettimeofday failed");
	if (time == SECOND)
		current_time = tv.tv_sec;
	else if (time == MILLISECOND)
		current_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	else if (time == MICROSECOND)
		current_time = (tv.tv_sec * 1000000) + tv.tv_usec;
	return (current_time);
}

void ft_usleep(long duration, t_data *data)
{
	long start;

	start = get_current_time(MILLISECOND);
	while (get_current_time(MILLISECOND) - start < duration)
	{
		if (check_dinner_finished(data) == true)
			break;
		usleep(100);
	}
}
