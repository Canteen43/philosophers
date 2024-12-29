/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:45 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 20:49:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_create_philos(t_main *main)
{
	int	i;

	main->philos = malloc(sizeof(t_philo) * main->nbr_philos);
	i = 0;
	gettimeofday(&main->starting_time, NULL);
	while (i < main->nbr_philos)
	{
		memset(&main->philos[i], 0, sizeof(t_philo));
		main->philos[i].main = main;
		main->philos[i].id = i + 1;
		main->philos[i].last_meal = main->starting_time;
		main->philos[i].fork_left = &main->forks[i];
		if (i + 1 < main->nbr_philos)
			main->philos[i].fork_right = &main->forks[i + 1];
		else
			main->philos[i].fork_right = &main->forks[0];
		pthread_create(&main->philos[i].thread, NULL, f_execute_philo,
			&main->philos[i]);
		i++;
	}
}
