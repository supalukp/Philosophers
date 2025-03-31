/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 13:48:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/31 15:53:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int destroy_all_mutex(t_data *data)
{
    int i;

    i = 0;
    if(pthread_mutex_destroy(&data->write_lock) != 0)
        return (exit_error("write_lock mutex destroy failed"));
    if(pthread_mutex_destroy(&data->table_lock) != 0)
        return (exit_error("table_lock mutex destroy failed"));
    while (i < data->philo_nbr)
    {
        if(pthread_mutex_destroy(&data->fork[i].fork_lock) != 0)
            return (exit_error("fork mutex destroy failed"));
        i++;
    }
    free(data->philo);
    free(data->fork);
    return (0);
}