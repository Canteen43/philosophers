/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_forks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:00:22 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:13:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_create_forks(t_main *main)
{
	int				i;

	i = 0;
	main->forks = malloc(main->nbr_philos * sizeof(pthread_mutex_t));
	while (i < main->nbr_philos)
	{
		pthread_mutex_init(&main->forks[i], NULL);
		i++;
	}
}
