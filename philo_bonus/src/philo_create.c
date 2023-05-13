/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:43:39 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:49:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

static int	init_philo(t_philo *philos)
{
	int	indx;

	indx = -1;
	while (++indx < get_table()->number_of_philo)
	{
		philos[indx].id = indx + 1;
		philos[indx].meal_ate.name = ft_itoa("/meal_ate", 9, indx + 1);
		philos[indx].last_meal.name = ft_itoa("/last_meal", 10, indx + 1);
		sem_unlink(philos[indx].meal_ate.name);
		sem_unlink(philos[indx].last_meal.name);
		philos[indx].meal_ate.lock = sem_open(philos[indx].meal_ate.name,
				O_CREAT, 0600, 1);
		philos[indx].last_meal.lock = sem_open(philos[indx].last_meal.name,
				O_CREAT, 0600, 1);
	}
	return (SUCCESS);
}

static int	create_process(t_philo *philos, int philo_number)
{
	int		indx;
	t_usec	start_time;

	indx = -1;
	start_time = get_time() + 200 * 1000;
	while (++indx < philo_number)
	{
		philos[indx].pid = fork();
		if (philos[indx].pid == 0)
			routine(&philos[indx], start_time);
	}
	return (SUCCESS);
}

int	philo_create(void)
{
	t_table	*table;

	table = get_table();
	if (init_philo(table->philos) == FAILURE
		|| create_process(table->philos, table->number_of_philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	wait_process(void)
{
	t_table	*table;
	int		indx;
	int		exit_status;

	indx = -1;
	table = get_table();
	while (++indx < table->number_of_philo)
	{
		waitpid(-1, &exit_status, 0);
		exit_status = *((char *)(&exit_status) + 1);
		if (exit_status == DEAD || exit_status == FAILURE)
		{
			kill_philos(table->philos);
			break ;
		}
	}
	return (SUCCESS);
}
