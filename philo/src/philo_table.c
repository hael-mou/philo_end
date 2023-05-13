/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:13:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 17:56:44 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

t_table	*get_table(void)
{
	static t_table	*inst;

	if (inst == NULL)
	{
		inst = malloc(sizeof(t_table));
		if (inst == NULL)
			return (printf("%s", ALC_ERROR), NULL);
		memset(inst, 0, sizeof(t_table));
	}
	return (inst);
}

int	init_table(int argc, char **argv)
{
	t_table	*table;

	table = get_table();
	if (table == NULL || parse_arguments(argc, argv) == FAILURE)
		return (FAILURE);
	table->philos = malloc(sizeof(t_philo) * table->number_of_philo);
	table->forks = malloc(sizeof(t_mutex) * table->number_of_philo);
	if (table->philos == NULL || table->forks == NULL)
		return (printf("%s\n", ALC_ERROR), FAILURE);
	memset(table->philos, 0, sizeof(t_philo) * table->number_of_philo);
	memset(table->forks, 0, sizeof(t_mutex) * table->number_of_philo);
	if (pthread_mutex_init(&table->start_sum.lock, NULL) == FAILURE
		|| pthread_mutex_init(&table->screen, NULL) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

void	clean_table(void)
{
	int		index;

	index = -1;
	if (get_table() == NULL)
		return ;
	if (get_table()->forks != NULL)
	{
		while (++index < get_table()->number_of_philo)
			pthread_mutex_destroy(&get_table()->forks[index]);
	}
	pthread_mutex_destroy(&get_table()->start_sum.lock);
	pthread_mutex_destroy(&get_table()->screen);
	free(get_table()->forks);
	free(get_table()->philos);
}
