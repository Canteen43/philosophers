/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_philo_died.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 13:39:52 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 13:48:23 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	f_philo_died(t_main *main)
{
	bool	result;

	result = false;
	pthread_mutex_lock(&main->death_lock);
	if (main->philo_died)
		result = true;
	pthread_mutex_unlock(&main->death_lock);
	return (result);
}
