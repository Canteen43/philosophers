/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_termination_condition_met.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 13:31:29 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/30 13:51:20 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	f_termination_condition_met(t_main *main)
{
	if (f_philo_died(main))
		return (true);
	if (f_philos_full(main))
		return (true);
	return (false);
}
