/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_increase_meal_count.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:23:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 16:00:29 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_increase_meal_count(t_philo *philo)
{
	philo->times_eaten++;
	if (philo->times_eaten == philo->main->must_eat)
	{
		pthread_mutex_lock(&philo->main->full_philos_lock);
		philo->main->full_philos_count++;
		pthread_mutex_unlock(&philo->main->full_philos_lock);
	}
}
