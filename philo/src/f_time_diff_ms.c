/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_time_diff_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 14:28:18 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/29 15:53:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	f_time_diff_ms(struct timeval *later, struct timeval *earlier)
{
	int	result;

	result = (later->tv_sec - earlier->tv_sec) * 1000 + (later->tv_usec
			- earlier->tv_usec) / 1000;
	return (result);
}
