/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:48:37 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/21 17:49:20 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data t_data;
typedef struct s_philo t_philo;

typedef struct s_data
{
	long			philo_nbr;
	long			time_to_die;
	long			time_to_eat;
	long			time_to_sleep;
	long			meal_nbr;
	t_philo			philo;
}

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	long			meals_eaten;
	long			last_meal_time;
	pthread_mutex_t	*right_folk;
	pthread_mutex_t	*left_folk;
	int				dead;
	t_data			*data;
}		

/***************PARSING****************/
long				ft_long_atoi(const char *nb);
long				nbr_inside_brackets(char *str);
int					only_digit(const char *str);
int					check_valid_input(int ac, char **av);
void				parse_input(t_data *data, int ac, char **av);

/*****************INITS****************/

/*****************UTILS****************/
void				exit_error(const char *error_msg);

#endif