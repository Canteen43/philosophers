/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:54:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 16:35:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	memset(&main, 0, sizeof(main));
	if (f_read_args(&main, argv) == -1)
		return (1);
	if (main.must_eat == 0)
		return (0);
	f_create_forks(&main);
	f_create_philos(&main);
	f_join_philos(&main);
	f_destroy_forks(&main);
	return (0);
}
