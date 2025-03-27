/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:14:46 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/27 16:12:52 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

long	ft_long_atoi(const char *nb)
{
	int			i;
	long int	num;
	int			negative;

	num = 0;
	i = 0;
	negative = 1;
	if (nb[i] == '-')
	{
		negative = -1;
		i++;
	}
	if (nb[i] < '0' || nb[i] > '9')
		return (-1);
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		num = (num * 10) + (nb[i] - '0');
		i++;
	}
	return (num * negative);
}

int	only_digit(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (1);
	}
	return (0);
}

int	check_valid_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (only_digit(av[i]))
			return (1);
		if (ft_long_atoi(av[i]) < 0 || ft_long_atoi(av[i]) > INT_MAX)
			return (1);
		if (i == 1 && ft_long_atoi(av[i]) >= 200)
			return (1);
		if (i >= 2 && i <= 4)
		{
			if (ft_long_atoi(av[i]) < 60)
				return (1);
		}
		i++;
	}
	return (0);
}

int	parse_input(t_data *data, int ac, char **av)
{
	if (ft_long_atoi(av[1]) == 0)
		return (1);
	if (check_valid_input(ac, av))
	{
		printf("Error Input Pattern: ./philo philo_nbr time_to_die time_to_eat time_to_sleep [nbr_meals]\n");
		return (1);
	}
	data->philo_nbr = ft_long_atoi(av[1]);
	data->time_to_die = ft_long_atoi(av[2]);
	data->time_to_eat = ft_long_atoi(av[3]);
	data->time_to_sleep = ft_long_atoi(av[4]);
	if (ac == 6)
		data->meal_nbr = ft_long_atoi(av[5]);
	else
		data->meal_nbr = -1;
	return (0);
}
