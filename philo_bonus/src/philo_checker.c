/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 01:07:35 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:45:36 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

static void	philo_is_dead(t_philo *philo)
{
	t_usec	death_time;

	death_time = get_table()->death_time;
	if (get_time() / 1000 - get_safeint_value(&philo->last_meal) >= death_time)
	{
		sem_wait(get_table()->screen);
		printf("%llu %d %s", get_time() / 1000, philo->id, "dead\n");
		exit(DEAD);
	}
}

static void	philos_is_ate(t_philo *philo)
{
	int		meal_count;
	int		meal_ate;

	meal_ate = get_safeint_value(&philo->meal_ate);
	meal_count = get_table()->meal_count;
	if (meal_count == -1 || meal_ate < meal_count)
		return ;
	philo_print(philo->id, get_time(), THINKING);
	exit(SUCCESS);
}

void	*scheduler(void	*arg)
{
	while (1)
	{
		philo_is_dead(arg);
		philos_is_ate(arg);
		usleep(2000);
	}
	return (NULL);
}

void	thread_scheduler(t_philo *philo)
{
	pthread_t	pthread;

	if (pthread_create(&pthread, NULL, &scheduler, philo))
		exit(FAILURE);
	pthread_detach(pthread);
}

void	kill_philos(t_philo *philos)
{
	int	indx;

	indx = -1;
	while (++indx < get_table()->number_of_philo)
		kill(philos[indx].pid, SIGKILL);
	while (++indx < get_table()->number_of_philo)
		waitpid(-1, NULL, 0);
}
