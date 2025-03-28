/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/28 17:41:11 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void create_philos_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_create(&data->philo[i].thread_id, NULL, #function, #virable) != 0)
            exit_error("Failed create threads");
        i++;
    }
    data->all_philos_created = true;
    data->start_dinner_time = get_current_time(MILLISECOND);
    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_join(data->philo[i], NULL) != 0)
            exit_error("Failed join threads");
        i++;
    }
}
