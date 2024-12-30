/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_monitor_death.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:17:59 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 14:14:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Static functions:
bool	sf_check_for_death(t_main *main, t_philo *philo);

void	f_monitor_death(t_main *main)
{
	int	i;

	i = 0;
	while (1)
	{
		if (f_philos_full(main))
			break ;
		if (sf_check_for_death(main, &main->philos[i]))
			break ;
		i++;
		if (i == main->nbr_philos)
		{
			i = 0;
			usleep(100);
		}
	}
}

bool	sf_check_for_death(t_main *main, t_philo *philo)
{
	struct timeval	current_time;
	struct timeval	meal_time;

	gettimeofday(&current_time, NULL);
	pthread_mutex_lock(&main->last_meal_lock);
	meal_time = philo->last_meal;
	pthread_mutex_unlock(&main->last_meal_lock);
	if (f_time_diff_ms(&current_time, &meal_time) > main->time_to_die)
	{
		pthread_mutex_lock(&main->death_lock);
		main->philo_died = true;
		pthread_mutex_unlock(&main->death_lock);
		f_print_state(philo, DEATH);
		return (true);
	}
	return (false);
}
