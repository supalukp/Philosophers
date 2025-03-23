/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 17:19:43 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/21 17:51:03 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void init(t_data *data)
{
    data->philo = malloc (sizeof(t_philo) * data->philo_nbr);
    if (!data->philo)
        exit_error("Fail Malloc");
    
}