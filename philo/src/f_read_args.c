/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:07:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 21:14:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Checks if given args are integers and adds given args to main struct.*/
int	f_read_args(t_main *main, int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (f_strtoi(argv[1], &main->nbr_philos) == -1 || main->nbr_philos <= 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (f_strtoi(argv[2], &main->time_to_die) == -1 || main->time_to_die <= 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (f_strtoi(argv[3], &main->time_to_eat) == -1 || main->time_to_eat <= 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	main->time_to_eat *= 1000;
	if (f_strtoi(argv[4], &main->time_to_sleep) == -1
		|| main->time_to_sleep <= 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	main->time_to_sleep *= 1000;
	main->must_eat = -1;
	if (argv[5] && f_strtoi(argv[5], &main->must_eat) == -1)
	{
		return (f_return_and_error(-1, WRONG_ARGS));
	}
	return (0);
}
