/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:54:28 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/25 21:21:02 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_main	main;

	if (argc != 5 && argc != 6)
		return (1);
	if (f_read_args(&main, argv) == -1)
		return (1);
	if (f_create_philos(&main) == -1)
		return (1);
}
