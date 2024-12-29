/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_monitor_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:17:59 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:46:29 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_monitor_death(t_main *main)
{
	int				i;
	struct timeval	current_time;

	i = 0;
	while (1)
	{
		if (main->full_philos_count == main->nbr_philos)
			break ;
		gettimeofday(&current_time, NULL);
		if (f_time_diff_ms(&current_time,
				&main->philos[i].last_meal) > main->time_to_die)
		{
			f_print_state(&main->philos[i], DEATH);
			main->philo_died = true;
			break ;
		}
		i++;
		if (i == main->nbr_philos)
			i = 0;
	}
}
