/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_termination_condition_met.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:31:29 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 14:34:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	f_termination_condition_met(t_main *main)
{
	if (main->philo_died)
		return (true);
	if (main->full_philos_count == main->nbr_philos)
		return (true);
	return (false);
}
