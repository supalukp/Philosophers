/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:17 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 14:53:59 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac >= 5 && ac <= 6)
	{
		if (parse_input(&data, ac, av))
			return (1);
		if (program_init(&data))
			return (1);
		if (philosophers_dining(&data))
			return (1);
		if (destroy_and_free(&data))
			return (1);
	}
	else
		return_error(WRONG_INPUT);
	return (0);
}
