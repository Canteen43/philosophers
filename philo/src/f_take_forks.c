/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_take_forks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:57:29 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 12:59:22 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	pthread_mutex_lock(philo->fork_right);
}
