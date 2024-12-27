/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:07:47 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/25 21:42:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Checks if given args are integers and adds given args to main struct.*/
int	f_read_args(t_main *main, int argc, char **argv)
{
	int	result;

	if (argc != 5 && argc != 6)
		return (f_return_and_error(-1, WRONG_ARG));
	if (fl_strtoi(arg[1], main->nbr_philos) == -1)
		return (f_return_and_error(-1, WRONG_ARG));
	if (fl_strtoi(arg[2], main->time_to_die) == -1)
		return (f_return_and_error(-1, WRONG_ARG));
	if (fl_strtoi(arg[3], main->time_to_eat) == -1)
		return (f_return_and_error(-1, WRONG_ARG));
	if (fl_strtoi(arg[4], main->time_to_sleep) == -1)
		return (f_return_and_error(-1, WRONG_ARG));
	main->must_eat = -1;
	if (argv[5] && fl_strtoi(arg[4], main->must_eat) == -1)
		return (f_return_and_error(-1, WRONG_ARG));
	return (0);
}
