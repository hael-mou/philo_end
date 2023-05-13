/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:16:02 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 17:59:26 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_diner.h"

int	ft_strcmp(char *string1, char *string2)
{
	size_t	i;

	i = 0;
	while (string1[i] && string1[i] == string2[i])
		i++;
	return ((unsigned char)string1[i] - (unsigned char)string2[i]);
}

int	philo_atoi(char *string)
{
	long long	nbr;

	nbr = 0;
	if (*string == '+')
		string++;
	while (*string >= '0' && *string <= '9')
	{
		nbr = nbr * 10 + (*string++) - '0';
		if (nbr > INT_MAX)
			return (FAILURE);
	}
	if (*string == 0)
		return (nbr);
	return (FAILURE);
}

void	philo_print(int philo_id, t_usec time, char *msg)
{
	pthread_mutex_lock(&get_table()->screen);
	if (get_safeint_value(&get_table()->start_sum) == START)
		printf("%llu %d %s", time / 1000, philo_id, msg);
	pthread_mutex_unlock(&get_table()->screen);
}
