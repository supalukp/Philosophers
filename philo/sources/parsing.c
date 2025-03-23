/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 10:14:46 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/21 15:35:46 by spunyapr         ###   ########.fr       */
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

long	nbr_inside_brackets(char *str)
{
	int		i;
	int		len;
	long	num;

	i = 0;
	num = 0;
	len = 0;
	while (str[len])
		len++;
	i = 0;
	if (str[i] != '[')
		return (-1);
	num = ft_long_atoi(str + 1);
	if (str[len - 1] != ']')
		return (-1);
	return (num);
}

int	check_valid_input(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (only_digit(av[i]))
			return (1);
		if (ft_long_atoi(av[i]) < 0 || ft_long_atoi(av[i]) > INT_MAX)
			return (1);
		if (i >= 2 && i <= 4)
		{
			if (ft_long_atoi(av[i]) < 60)
				return (1);
		}
		i++;
	}
	if (ac == 6)
	{
		if (nbr_inside_brackets(av[5]) == -1)
			return (1);
		if (nbr_inside_brackets(av[5]) < 0
			|| nbr_inside_brackets(av[5]) > INT_MAX)
			return (1);
	}
	return (0);
}

void	parse_input(t_data *data, int ac, char **av)
{
	if (ft_long_atoi(av[1]) == 0)
		exit(1);
	if (check_valid_input(ac, av))
		return (exit_error("Wrong Input: ./philo 5 200 800 800 [5] (EXAMPLE)"));
	data->philo_nbr = ft_long_atoi(av[1]);
	data->time_to_die = ft_long_atoi(av[2]);
	data->time_to_eat = ft_long_atoi(av[3]);
	data->time_to_sleep = ft_long_atoi(av[4]);
	if (ac == 6)
		data->meal_nbr = nbr_inside_brackets(av[5]);
}
