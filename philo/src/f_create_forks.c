/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:00:22 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 15:16:56 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_create_forks(t_main *main)
{
	pthread_mutex_t	mutex;
	int				i;

	i = 0;
	while (i < main->nbr_philos)
	{
		pthread_mutex_init(&mutex, NULL);
		main->forks[i] = mutex;
		i++;
	}
}