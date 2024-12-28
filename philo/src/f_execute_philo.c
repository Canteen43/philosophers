/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_execute_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:17:33 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 16:41:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*f_execute_philo(void *main)
{
	int				philo_id;
	pthread_mutex_t	fork_left;
	pthread_mutex_t	fork_right;

	philo_id = main->philo_id;
	if (philo_id % 2 == 1)
		usleep(main->time_to_eat);
	f_attempt_taking_fork(fork_left);
	f_attempt_taking_fork(fork_right);
	f_eat();
	f_sleep();
	f_think();
}
