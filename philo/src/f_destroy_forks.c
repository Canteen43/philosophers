/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_destroy_forks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:00:22 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 10:51:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_destroy_forks(t_main *main)
{
	int				i;

	i = 0;
	while (i < main->nbr_philos)
	{
		pthread_mutex_destroy(&main->forks[i]);
		i++;
	}
	free(main->forks);
}
