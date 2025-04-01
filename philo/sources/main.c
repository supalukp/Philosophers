/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:17 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/01 10:56:33 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data data;
	
	if (ac >= 5 && ac <= 6)
	{
		if (parse_input(&data, ac, av) == 1)
			return (1);
		//debug_parsing(&data);
		if (program_init(&data) == 1)
			return (1);
		if (main_program(&data) == 1)
			return (1);
		if (destroy_all_mutex(&data) == 1)
			return (1);
	}
	else
		return_error("Error: Example of good agrument\n./philo 5 200 800 800 [5]");
	return (0);
}
