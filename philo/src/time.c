/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 01:45:19 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/11 12:54:34 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

t_usec	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000000 + time.tv_usec);
}

void	sleep_ms(t_usec start_time, t_usec stime_ms)
{
	while (get_time() - start_time < stime_ms * 1000)
	{
		if (get_safeint_value(&get_table()->start_sum) == STOP)
			break ;
		usleep(200);
	}
}
