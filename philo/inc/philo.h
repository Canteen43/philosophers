/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/22 21:05:15 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>  // For printf()
# include <stdlib.h> // For malloc(), free()
# include <string.h> // For memset()
# include <unistd.h> // For write(), usleep()
# include <sys/time.h> // For gettimeofday()
# include <pthread.h> // For pthread_create(), pthread_detach(), pthread_join(),
	// pthread_mutex_init(), pthread_mutex_destroy(),
	// pthread_mutex_lock(), pthread_mutex_unlock()

// Macros
# define EXAMPLE "example"

// Main struct
typedef struct s_main
{
	int						nbr_philos;
	int						time_to_die;
	int						time_to_eat;
	int						time_to_sleep;
	int						must_eat;
}							t_main;

// Function declarations

#endif // PHILO_H
