/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philos_full.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:52 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 14:14:26 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	f_philos_full(t_main *main)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&main->full_philos_lock);
	if (main->full_philos_count == main->nbr_philos)
		result = true;
	pthread_mutex_unlock(&main->full_philos_lock);
	return (result);
}
