/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:17:33 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 21:57:31 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Static functions:
static void	*sf_one_philo(t_philo *philo);

void	*f_execute_philo(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->main->nbr_philos == 1)
		return (sf_one_philo(philo));
	if (philo->id % 2 == 1)
		usleep(philo->main->time_to_eat / 2);
	while (1)
	{
		f_take_forks(philo);
		if (f_termination_condition_met(philo->main))
		{
			f_release_forks(philo);
			break ;
		}
		f_eat(philo);
		f_release_forks(philo);
		if (f_termination_condition_met(philo->main))
			break ;
		f_sleep(philo);
		if (f_termination_condition_met(philo->main))
			break ;
		f_think(philo);
	}
	return (NULL);
}

static void	*sf_one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	f_print_state(philo, FORK);
	usleep(philo->main->time_to_die * 1500);
	return (NULL);
}
