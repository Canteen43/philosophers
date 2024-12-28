/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_create_philos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:19:45 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 16:52:13 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_create_philos(t_main *main)
{
	pthread_t	thread;
	int			i;

	i = 0;
	while (i < main->nbr_philos)
	{
		pthread_create(&thread, NULL, f_execute_philo, &i);
		main->philos[i] = thread;
		i++;
	}
}
