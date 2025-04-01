/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:41:45 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/01 17:49:08 by spunyapr         ###   ########.fr       */
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
        if (pthread_create(&data->philo[i].thread_id, NULL, philo_routine, data) != 0)
            return(return_error("Failed create threads"));
        i++;
    }
    data->all_philos_created = true;
    data->start_dinner_time = get_current_time(MILLISECOND);
    printf("%ld\n",data->start_dinner_time);
    i = 0;
    while (i < data->philo_nbr)
    {
        if (pthread_join(data->philo[i].thread_id, NULL) != 0)
            return_error("Failed join threads");
        i++;
    }
    return (0);
}

void philo_routine(void *data)
{
    t_philo *philo;

    philo = (void *)data;
   
    while (check_all_threads_created(philo->data) == false);
    //Set last meal time = start time
    philo->last_meal_time = get_current_time(MILLISECOND);
    //loop until dinner finish
    while (check_dinner_finished(philo->data) != true)
    {
        if (philo->full == true)
            break;
        // eat();
        // sleep();
        // think();
    }
}
