/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_table.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:13:16 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 11:22:46 by hael-mou         ###   ########.fr       */
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
	sem_unlink("/forks");
	sem_unlink("/screen");
	table->forks = sem_open("/forks", O_CREAT, 0600, table->number_of_philo);
	table->screen = sem_open("/screen", O_CREAT, 0600, 1);
	table->philos = malloc(sizeof(t_philo) * table->number_of_philo);
	if (table->forks == SEM_FAILED || table->screen == SEM_FAILED
		|| table->philos == NULL)
		return (printf("%s\n", ALC_ERROR), FAILURE);
	memset(table->philos, 0, sizeof(t_philo) * table->number_of_philo);
	return (SUCCESS);
}

void	clean_table(void)
{
	int		index;

	index = -1;
	if (get_table() == NULL)
		return ;
	sem_close(get_table()->forks);
	sem_close(get_table()->screen);
	free(get_table()->philos);
	sem_unlink("/forks");
	sem_unlink("/screen");
	sem_unlink("/meal_ate");
	sem_unlink("/last_meal");
}
