/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 14:24:01 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/28 17:40:10 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	exit_error(const char *error_msg)
{
	printf("%s\n", error_msg);
	return (1);
}

long	get_current_time(t_time time)
{
	struct timeval	time;
	long current_time;

	current_time = 0;
	if (gettimeofday(&time, NULL) == -1)
		exit_error("gettimeofdat failed");
	if (time == SECOND)
		current_time = tv.tv_sec;
	else if (time == MILLISECOND)
		current_time = time.tv_sec * 1000 + time.tv_usec / 1000;
	else if (time == MICROSECOND)
		current_time = tv.tv_sec * 1000000 + tv.tv_usec;
	return (current_time);
}
