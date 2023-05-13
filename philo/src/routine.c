/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:34:20 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/12 16:49:55 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

static void	eating(t_philo *philo, int duration)
{
	t_usec	eating_time;
	int		meal_ate;

	pthread_mutex_lock(philo->lfork);
	philo_print(philo->id, get_time(), TAKING);
	pthread_mutex_lock(philo->rfork);
	eating_time = get_time();
	set_safeint_value(&philo->last_meal, eating_time / 1000);
	philo_print(philo->id, eating_time, TAKING);
	philo_print(philo->id, eating_time, EATING);
	meal_ate = get_safeint_value(&philo->meal_ate) + 1;
	sleep_ms(eating_time, duration);
	set_safeint_value(&philo->meal_ate, meal_ate);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

static void	sleeping(t_philo *philo, int duration)
{
	t_usec	time;

	time = get_time();
	philo_print(philo->id, time, SLEEPING);
	sleep_ms(time, duration);
}

static void	thinking(t_philo *philo)
{
	philo_print(philo->id, get_time(), THINKING);
}

void	*routine(void	*arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	set_safeint_value(&philo->last_meal, get_time() / 1000);
	if (philo->id % 2 != 0)
	{
		thinking(philo);
		sleep_ms(get_time(), get_table()->meal_duration * 0.8 + 1);
	}
	while (get_safeint_value(&get_table()->start_sum))
	{
		eating(philo, get_table()->meal_duration);
		sleeping(philo, get_table()->sleep_duration);
		thinking(philo);
	}
	return (NULL);
}
