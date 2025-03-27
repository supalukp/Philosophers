/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:17 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/27 16:13:59 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data data;

	if (ac >= 5 && ac <= 6)
	{
		if (!parse_input(&data, ac, av))
			debug_parsing(&data);
		// Initialize
		program_init(&data);
	}
	else
	{
		exit_error("Error: Example of good agrument\n./philo 5 200 800 800 [5]");
	}
}
