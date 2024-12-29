/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_take_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:57:29 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 21:37:49 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	f_print_state(philo, FORK);
	pthread_mutex_lock(philo->fork_right);
	f_print_state(philo, FORK);
}
