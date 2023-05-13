/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 21:43:39 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 19:53:28 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

static int	create_forks(t_mutex *forks, int number_forks)
{
	int				index;

	index = -1;
	while (++index < number_forks)
	{
		if (pthread_mutex_init(&forks[index], NULL) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}

static int	init_philo(t_philo *philos, t_mutex *forks)
{
	int	indx;

	indx = -1;
	while (++indx < get_table()->number_of_philo)
	{
		philos[indx].id = indx + 1;
		philos[indx].lfork = &forks[indx];
		philos[indx].rfork = &forks[(indx + 1) % get_table()->number_of_philo];
		pthread_mutex_init(&philos[indx].meal_ate.lock, NULL);
		pthread_mutex_init(&philos[indx].last_meal.lock, NULL);
	}
	return (SUCCESS);
}

static int	create_thread(t_philo *philos, int philo_number)
{
	int	indx;

	indx = -1;
	set_safeint_value(&get_table()->start_sum, START);
	while (++indx < philo_number)
	{
		if (pthread_create(&philos[indx].thread, NULL, &routine, &philos[indx]))
		{
			set_safeint_value(&get_table()->start_sum, STOP);
			return (FAILURE);
		}
	}
	usleep(200);
	if (pthread_create(&get_table()->scheduler, NULL, &scheduler, get_table()))
	{
		set_safeint_value(&get_table()->start_sum, STOP);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	philo_create(void)
{
	t_table	*table;

	table = get_table();
	if (create_forks(table->forks, table->number_of_philo) == FAILURE
		|| init_philo(table->philos, table->forks) == FAILURE
		|| create_thread(table->philos, table->number_of_philo) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int	join_threads(void)
{
	int	index;

	index = -1;
	if (pthread_join(get_table()->scheduler, NULL))
		return (FAILURE);
	while (++index < get_table()->number_of_philo)
	{
		if (pthread_join(get_table()->philos[index].thread, NULL))
			return (FAILURE);
	}
	return (SUCCESS);
}
