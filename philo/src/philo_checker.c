/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:07:35 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 20:01:16 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

int	philo_is_dead(void)
{
	int		index;
	t_usec	death_time;
	t_philo	*philos;

	index = -1;
	philos = get_table()->philos;
	death_time = get_table()->death_time;
	while (++index < get_table()->number_of_philo)
	{
		if (get_time() / 1000
			- get_safeint_value(&philos[index].last_meal) >= death_time)
		{
			set_safeint_value(&get_table()->start_sum, STOP);
			printf("%llu %d %s\n", get_time() / 1000, philos[index].id, "died");
			return (SUCCESS);
		}
	}
	return (FAILURE);
}

int	philos_is_ate(void)
{
	int		index;
	int		meal_count;
	t_philo	*philos;
	int		meal_ate;

	index = -1;
	philos = get_table()->philos;
	meal_count = get_table()->meal_count;
	while (++index < get_table()->number_of_philo)
	{
		meal_ate = get_safeint_value(&philos[index].meal_ate);
		if (meal_count == -1 || meal_ate < meal_count)
			return (FAILURE);
	}
	set_safeint_value(&get_table()->start_sum, STOP);
	usleep(1000);
	printf("All Philosophers ate at least %d times\n", meal_count);
	return (SUCCESS);
}

void	*scheduler(void	*arg)
{
	t_table	*table;

	table = (t_table *)arg;
	while (get_safeint_value(&table->start_sum) == START)
	{
		if (philo_is_dead() == SUCCESS || philos_is_ate() == SUCCESS)
			set_safeint_value(&table->start_sum, STOP);
		usleep(200);
	}
	return (NULL);
}
