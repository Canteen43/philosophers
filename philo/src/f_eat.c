/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_eat.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 11:33:59 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 21:41:15 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_eat(t_philo *philo)
{
	gettimeofday(&philo->last_meal, NULL);
	f_print_state(philo, EAT);
	f_increase_meal_count(philo);
	usleep(philo->main->time_to_eat);
}
