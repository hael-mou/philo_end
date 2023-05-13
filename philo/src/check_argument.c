/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_argument.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 11:57:38 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 19:52:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

int	check_arguments(int argc, char **argv)
{
	if (argc == 6 || argc == 5)
		return (SUCCESS);
	if (argc == 2 && ft_strcmp(argv[1], "-help") == 0)
		printf("%s", HELP);
	else
		printf("%s", NARG_ERROR);
	return (FAILURE);
}

int	parse_arguments(int argc, char **argv)
{
	int		*table_info[5];
	int		index;

	if (get_table() == NULL)
		return (FAILURE);
	index = -1;
	table_info[0] = &get_table()->number_of_philo;
	table_info[1] = &get_table()->death_time;
	table_info[2] = &get_table()->meal_duration;
	table_info[3] = &get_table()->sleep_duration;
	table_info[4] = &get_table()->meal_count;
	*table_info[4] = -1;
	while (++index < argc - 1)
	{
		*table_info[index] = philo_atoi(argv[index + 1]);
		if (*table_info[index] <= 0)
			return (printf("%s", ARG_ERROR), FAILURE);
	}
	return (SUCCESS);
}
