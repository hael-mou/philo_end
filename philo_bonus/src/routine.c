/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 00:34:20 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:49:25 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

static void	eating(t_philo *philo, int duration)
{
	t_usec	eating_time;
	int		meal_ate;

	sem_wait(get_table()->forks);
	philo_print(philo->id, get_time(), TAKING);
	sem_wait(get_table()->forks);
	eating_time = get_time();
	set_safeint_value(&philo->last_meal, eating_time / 1000);
	philo_print(philo->id, eating_time, TAKING);
	philo_print(philo->id, eating_time, EATING);
	meal_ate = get_safeint_value(&philo->meal_ate) + 1;
	sleep_ms(eating_time, duration * 1000);
	set_safeint_value(&philo->meal_ate, meal_ate);
	sem_post(get_table()->forks);
	sem_post(get_table()->forks);
}

static void	sleeping(t_philo *philo, int duration)
{
	t_usec	time;

	time = get_time();
	philo_print(philo->id, time, SLEEPING);
	sleep_ms(time, duration * 1000);
}

static void	thinking(t_philo *philo)
{
	philo_print(philo->id, get_time(), THINKING);
}

void	routine(t_philo *philo, t_usec start_time)
{
	start_time += (philo->id % 2 != 0) * 800;
	sleep_ms(get_time(), start_time - get_time());
	set_safeint_value(&philo->last_meal, get_time() / 1000);
	thread_scheduler(philo);
	if (philo->id % 2 != 0)
	{
		thinking(philo);
		sleep_ms(get_time(), get_table()->meal_duration * 400);
	}
	while (1)
	{
		eating(philo, get_table()->meal_duration);
		sleeping(philo, get_table()->sleep_duration);
		thinking(philo);
	}
}
