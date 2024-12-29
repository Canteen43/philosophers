/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_destroy_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:00:22 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:13:36 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_destroy_forks(t_main *main)
{
	pthread_mutex_t	mutex;
	int				i;

	i = 0;
	while (i < main->nbr_philos)
	{
		mutex = main->forks[i];
		pthread_mutex_destroy(&mutex);
		i++;
	}
	free(main->forks);
}
