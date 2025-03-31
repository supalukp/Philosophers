/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/31 16:08:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main_program(t_data *data)
{
    if (create_philos_threads(data) == 1)
    {
        return (1);
    }
    return (0);
}

int create_philos_threads(t_data *data)
{
    int i;

    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_create(&data->philo[i].thread_id, NULL, #function, #virable) != 0)
            return(exit_error("Failed create threads"));
        i++;
    }
    data->all_philos_created = true;
    data->start_dinner_time = get_current_time(MILLISECOND);
    printf("%ld\n",data->start_dinner_time);
    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_join(data->philo[i].thread_id, NULL) != 0)
            exit_error("Failed join threads");
        i++;
    }
    return (0);
}
