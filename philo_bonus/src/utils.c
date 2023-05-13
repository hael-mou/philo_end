/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 22:16:02 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:49:49 by hael-mou         ###   ########.fr       */
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
	sem_wait(get_table()->screen);
	printf("%llu %d %s", time / 1000, philo_id, msg);
	sem_post(get_table()->screen);
}

static int	ft_nbrlen(int number)
{
	int	len;

	len = 0;
	while (number > 0)
	{
		number /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(char *s, int s_len, int number)
{
	char	*string;
	int		len;
	int		index;

	index = -1;
	len = ft_nbrlen(number) + s_len + 1;
	string = malloc(len + 1);
	memset(string, 0, len + 1);
	if (string == NULL)
		return (NULL);
	while (s[++index])
		string[index] = s[index];
	string[index] = '_';
	while (number > 0)
	{
		string[--len] = number % 10 + '0';
		number /= 10;
	}
	return (string);
}
