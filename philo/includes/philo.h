/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:48:37 by spunyapr          #+#    #+#             */
/*   Updated: 2025/03/27 15:06:58 by spunyapr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;
typedef struct s_fork	t_fork;

struct					s_fork
{
	pthread_mutex_t		*fork_lock;
	bool				fork_taken;
	bool				fork_created;
};

struct					s_data
{
	long				philo_nbr;
	long				time_to_die;
	long				time_to_eat;
	long				time_to_sleep;
	long				meal_nbr;
	t_philo				*philo;
	t_fork				*fork;
	pthread_mutex_t		*write_lock;
	pthread_mutex_t		*table_lock;
	bool				all_philos_created;
	long				start_dinner_time;
	bool				end_dinner;
	pthread_t			monitor;
};

struct					s_philo
{
	pthread_t			thread_id;
	int					id;
	long				meals_eaten;
	bool				full;
	bool				dead;
	long				last_meal_time;
	int					right_folk;
	int					left_folk;
	t_data				*data;
};

/***************PARSING****************/
long					ft_long_atoi(const char *nb);
long					nbr_inside_brackets(char *str);
int						only_digit(const char *str);
int						check_valid_input(int ac, char **av);
int						parse_input(t_data *data, int ac, char **av);

/*****************INITS****************/
void					program_init(t_data *data);
void					data_init(t_data *data);
void					philos_init(t_data *data);

/*****************UTILS****************/
int						exit_error(const char *error_msg);

/*****************DEBUG****************/
void					debug_parsing(t_data *data);

#endif