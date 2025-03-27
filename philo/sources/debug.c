/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:19:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/27 16:13:40 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	debug_parsing(t_data *data)
{
	printf("philo_nbr = %ld\n", data->philo_nbr);
	printf("time_to_die = %ld\n", data->time_to_die);
	printf("time_to_eat = %ld\n", data->time_to_eat);
	printf("time_to_sleep = %ld\n", data->time_to_sleep);
	printf("meal_nbr = %ld\n", data->meal_nbr);
}
