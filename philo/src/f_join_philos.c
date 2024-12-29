/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_join_philos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:39:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:49:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	f_join_philos(t_main *main)
{
	int	i;

	i = 0;
	while (i < main->nbr_philos)
	{
		pthread_join(main->philos[i].thread, NULL);
		i++;
	}
	free(main->philos);
}
