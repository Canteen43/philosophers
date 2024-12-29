/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:54:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// For pthread functions
# include <pthread.h>
// For printf()
# include <stdio.h>
// For malloc(), free()
# include <stdlib.h>
// For memset()
# include <string.h>
// For gettimeofday()
# include <sys/time.h>
// For write(), usleep()
# include <unistd.h>
// For true, false
# include <stdbool.h>
// For INTMAX, INTMIN
# include <limits.h>

// Macros
# define WRONG_ARGS "Wrong arguments. Try: nbr die eat sleep (must_eat)"
# define FORK "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DEATH "died"

// Main struct
typedef struct s_main
{
	int						nbr_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat;
	struct timeval			*starting_time;
	pthread_mutex_t			*forks;
	pthread_mutex_t			*print_lock;
	pthread_mutex_t			*full_philos_lock;
	struct s_philosophers	*philos;
	int						full_philos_count;
	bool					philo_died;
}							t_main;

// Philosopher struct
typedef struct s_philosophers
{
	t_main					*main;
	int						id;
	pthread_t				thread;
	pthread_mutex_t			*fork_left;
	pthread_mutex_t			*fork_right;
	int						times_eaten;
	struct timeval			last_meal;
}							t_philo;

// Function declarations
int							f_return_and_error(int return_code, char *message);
int							f_read_args(t_main *main, int argc, char **argv);
void						f_create_forks(t_main *main);
void						f_create_philos(t_main *main);
void						f_destroy_forks(t_main *main);
void						f_eat(t_philo *philo);
void						*f_execute_philo(void *philo);
void						f_join_philos(t_main *main);
void						f_print_state(t_philo *philo, char *state);
void						f_take_forks(t_philo *philo);
void						f_release_forks(t_philo *philo);
void						f_sleep(t_philo *philo);
void						f_think(t_philo *philo);
bool						f_termination_condition_met(t_main *main);
int							f_time_diff_ms(struct timeval *later,
								struct timeval *earlier);
void						f_monitor_death(t_main *main);
void						f_increase_meal_count(t_philo *philo);
int							f_strtoi(char *str, int *num);
size_t						f_strlen(char *str);
#endif // PHILO_H
