/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 21:28:20 by kweihman          #+#    #+#             */
/*   Updated: 2024/12/25 21:32:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*Returns the length of a str. Similar to strlen. Returns 0 for invalid strings.
*/
size_t	f_strlen(char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
