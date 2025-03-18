/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 09:54:17 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/18 20:37:31 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int main (int ac, char **av)
{
    t_dinner dinner;
    
    if (ac >= 5 && ac <= 6)
    {
        parse_input(&dinner, ac, av);
        printf("ok\n");
    }
    else
    {
        exit_error("Error: Example of good agrument\n./philo 5 200 800 800 [5]");
    }
}