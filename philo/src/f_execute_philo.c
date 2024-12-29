/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:17:33 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:36:28 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*f_execute_philo(void *input)
{
	t_philo	*philo;

	philo = (t_philo *)input;
	if (philo->id % 2 == 1)
		usleep(philo->main->time_to_eat);
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
		f_increase_meal_count(philo);
		if (f_termination_condition_met(philo->main))
			break ;
		f_sleep(philo);
		if (f_termination_condition_met(philo->main))
			break ;
		f_think(philo);
	}
	return (NULL);
}
