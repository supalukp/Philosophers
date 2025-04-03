/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:19:33 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/03 15:16:17 by spunyapr         ###   ########.fr       */
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
	printf("\n---------------\n");
}
void debug_t_data(t_data *data)
{
	printf("philo_nbr = %ld\n", data->philo_nbr);
	printf("time_to_die = %ld\n", data->time_to_die);
	printf("time_to_eat = %ld\n", data->time_to_eat);
	printf("time_to_sleep = %ld\n", data->time_to_sleep);
	printf("meal_nbr = %ld\n", data->meal_nbr);
	if (data->all_philos_created == true)
		printf("all_philos_created is true\n");
	else
		printf("all_philos_created is false\n");
	if (data->end_dinner == true)
		printf("end_dinner is true\n");
	else
		printf("end_dinner is false\n");
	printf("\n---------------\n");
}
