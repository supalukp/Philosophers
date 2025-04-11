/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spunyapr <spunyapr@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 16:48:37 by spunyapr          #+#    #+#             */
/*   Updated: 2025/04/10 15:10:13 by spunyapr         ###   ########.fr       */
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

# define WRONG_INPUT \
	"Error: Wrong input: ./philo time_to_die time_to_eat \
time_to_sleep [number_of_times_each_philosopher_must_eat]\n"

typedef enum e_time
{
	SECOND,
	MILLISECOND,
	MICROSECOND
}						t_time;

typedef enum e_status
{
	EATING,
	SLEEPING,
	THINKING,
	TAKE_FORK_LEFT,
	TAKE_FORK_RIGHT,
	TAKE_FORK,
	DIED
}						t_status;

struct					s_fork
{
	pthread_mutex_t		fork_lock;
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
	pthread_mutex_t		write_lock;
	pthread_mutex_t		table_lock;
	bool				all_philos_created;
	long				threads_running;
	long				start_dinner_time;
	long				set_meal_time;
	long				all_full;
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
	int					right_fork;
	int					left_fork;
	pthread_mutex_t		philo_lock;
	t_data				*data;
};

/***************PARSING****************/
int						parse_input(t_data *data, int ac, char **av);

/*****************INITS****************/
int						program_init(t_data *data);

/****************PROGRAM***************/
int						philosophers_dining(t_data *data);
void					*philo_routine(void *data);
int						eat(t_philo *philo);
void					think(t_philo *philo);
void					philo_sleep(t_philo *philo);

// /****************MONITOR***************/
void					*monitor_all_philos(void *arg);

/*****************MUTEX****************/
int						set_bool(pthread_mutex_t *mutex, bool *dest,
							bool value);
bool					get_bool(pthread_mutex_t *mutex, bool *value);
int						set_long(pthread_mutex_t *mutex, long *dest,
							long value);
long					get_long(pthread_mutex_t *mutex, long *value);
bool					check_all_threads_created(t_data *data);
bool					check_dinner_finished(t_data *data);
int						incr_long(pthread_mutex_t *mutex, long *dest,
							long value);
void					wait_set_meal_time(t_philo *philo);

/*****************WRITE****************/
int						write_mutex_lock(t_philo *philo, t_status status);

/*****************UTILS****************/
int						return_error(const char *error_msg);
long					get_current_time(void);
void					ft_usleep(long duration, t_data *data);

/*****************DEBUG****************/
void					debug_parsing(t_data *data);
void					debug_t_philo(t_data *data);
void					debug_t_data(t_data *data);

/*****************CLEAN****************/
int						destroy_and_free(t_data *data);

#endif