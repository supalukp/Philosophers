/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:19:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/02 14:46:40 by spunyapr         ###   ########.fr       */
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


void debug_t_philo(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->philo_nbr)
	{
		printf("id = %d\n", data->philo[i].id);
		printf("meals eaten = %ld\n", data->philo[i].meals_eaten);
		if (data->philo->full == true)
			printf("philo id %d is full\n", data->philo[i].id);
		else
			printf("philo id %d is not full\n", data->philo[i].id);
		printf("philo id %d -> right_fork id = %d\n", data->philo[i].id, data->philo[i].right_folk);
		printf("philo id %d -> left_fork id = %d\n", data->philo[i].id, data->philo[i].left_folk);
		i++;
	}
}