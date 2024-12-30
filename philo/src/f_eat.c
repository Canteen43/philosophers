/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:33:59 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 13:58:07 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->main->last_meal_lock);
	gettimeofday(&philo->last_meal, NULL);
	pthread_mutex_unlock(&philo->main->last_meal_lock);
	f_print_state(philo, EAT);
	f_increase_meal_count(philo);
	usleep(philo->main->time_to_eat);
}
