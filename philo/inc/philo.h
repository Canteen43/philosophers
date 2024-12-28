/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 14:54:38 by kweihman         ###   ########.fr       */
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

// Macros
# define WRONG_ARGS "Wrong arguments. Args: nbr die eat sleep must_eat"

// Main struct
typedef struct s_main
{
	int				nbr_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	struct timeeval	current_time;
	pthread_mutex_t
}					t_main;

// Function declarations
int					f_return_and_error(int return_code, char *message);
int					f_read_args(t_main *main, int argc, char **argv);

#endif // PHILO_H
