/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:17 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/08 13:45:02 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac >= 5 && ac <= 6)
	{
		// parsing
		if (parse_input(&data, ac, av) == 1)
			return (1);
		//debug_parsing(&data);
		// init
		if(program_init(&data))
			return (1);
		//debug_t_data(&data);
		debug_t_philo(&data);
		// program
		create_philos_threads(&data);
		//create_monitor_threads(&data);
		// free
		destroy_all_mutex(&data);
	}
	else
		return_error("Error: Example of good agrument\n./philo 5 200 800 800 [5]");
	return (0);
}
