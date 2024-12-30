/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:54:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 13:55:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	memset(&main, 0, sizeof(main));
	if (f_read_args(&main, argc, argv) == -1)
		return (1);
	if (main.must_eat == 0)
		return (0);
	pthread_mutex_init(&main.print_lock, NULL);
	pthread_mutex_init(&main.full_philos_lock, NULL);
	pthread_mutex_init(&main.death_lock, NULL);
	pthread_mutex_init(&main.last_meal_lock, NULL);
	f_create_forks(&main);
	f_create_philos(&main);
	f_monitor_death(&main);
	f_join_philos(&main);
	f_destroy_forks(&main);
	pthread_mutex_destroy(&main.print_lock);
	pthread_mutex_destroy(&main.full_philos_lock);
	pthread_mutex_destroy(&main.death_lock);
	pthread_mutex_destroy(&main.last_meal_lock);
	return (0);
}
