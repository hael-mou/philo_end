/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_diner.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 02:30:26 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:16:09 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

int	main(int argc, char **argv)
{
	int		index;
	int		(*program_step[4])();

	index = -1;
	program_step[0] = check_arguments;
	program_step[1] = init_table;
	program_step[2] = philo_create;
	program_step[3] = wait_process;
	while (++index < 4)
	{
		if ((program_step[index])(argc, argv) == FAILURE)
		{
			clean_table();
			return (EXIT_FAILURE);
		}
	}
	clean_table();
	return (EXIT_SUCCESS);
}
