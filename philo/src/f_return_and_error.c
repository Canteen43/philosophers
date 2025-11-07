/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_return_and_error.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:25:36 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/25 21:33:33 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Writes a given message to STDERR and then returns given return_code.*/
int	f_return_and_error(int return_code, char *message)
{
	int ret;

	ret = write(STDERR_FILENO, message, f_strlen(message));
	(void)ret;
	return (return_code);
}
