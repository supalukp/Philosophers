/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 22:32:48 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/09 22:36:15 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void wait_set_meal_time(t_philo *philo)
{
    while (get_long(&philo->data->table_lock, &philo->data->set_meal_time) != philo->data->philo_nbr);
}
