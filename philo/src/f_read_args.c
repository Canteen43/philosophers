/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:07:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/28 14:54:46 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Checks if given args are integers and adds given args to main struct.*/
int	f_read_args(t_main *main, int argc, char **argv)
{
	int	result;

	if (argc != 5 && argc != 6)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (fl_strtoi(arg[1], main->nbr_philos) == -1 || main->nbr_philos < 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (fl_strtoi(arg[2], main->time_to_die) == -1 || main->time_to_die < 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (fl_strtoi(arg[3], main->time_to_eat) == -1 || main->time_to_eat < 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	if (fl_strtoi(arg[4], main->time_to_sleep) == -1 || main->time_to_sleep < 0)
		return (f_return_and_error(-1, WRONG_ARGS));
	main->must_eat = -1;
	if (argv[5] && fl_strtoi(arg[4], main->must_eat) == -1)
		return (f_return_and_error(-1, WRONG_ARGS));
	return (0);
}