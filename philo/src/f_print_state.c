/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_state.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 12:14:09 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 22:11:08 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_print_state(t_philo *philo, char *state)
{
	struct timeval	current_time;
	int				time_diff;

	if (philo->main->philo_died)
		return ;
	gettimeofday(&current_time, NULL);
	time_diff = f_time_diff_ms(&current_time, &philo->main->starting_time);
	pthread_mutex_lock(&philo->main->print_lock);
	printf("%d %d %s\n", time_diff, philo->id, state);
	pthread_mutex_unlock(&philo->main->print_lock);
}
