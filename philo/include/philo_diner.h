/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_diner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:22:43 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 19:51:21 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_DINER_H
# define PHILO_DINER_H

/*###############################################################
#  	   * Includes :		    								 	#
###############################################################*/
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>
# include "message.h"
# include "safe_int.h"

/*###############################################################
#  	   * Define :		    								 	#
###############################################################*/
// return value :
# define SUCCESS	0
# define FAILURE	-1

// Sum status :
# define START		1
# define STOP		0

// Sum status :
# define LOCK		1
# define UNLOCK		0

// typedef :
typedef unsigned long long int	t_usec;
typedef pthread_mutex_t			t_mutex;

/*###############################################################
#  	   * struct	:												#
###############################################################*/
typedef struct s_philo
{
	int			id;
	pthread_t	thread;
	t_mutex		*lfork;
	t_mutex		*rfork;
	t_safeint	meal_ate;
	t_safeint	last_meal;
}	t_philo;

// diner table :
typedef struct s_table
{
	int			death_time;
	int			meal_duration;
	int			sleep_duration;
	int			number_of_philo;
	int			meal_count;
	t_safeint	start_sum;
	t_mutex		screen;
	t_philo		*philos;
	t_mutex		*forks;
	pthread_t	scheduler;
}	t_table;

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// check argument :
int		check_arguments(int argc, char **argv);
int		parse_arguments(int argc, char **argv);

//philo thread :
int		philo_create(void);
int		join_threads(void);

//philo routine :
void	*routine(void *arg);

//philo scheduler :
void	*scheduler(void	*arg);

// philo_table :
t_table	*get_table(void);
int		init_table(int argc, char **argv);
void	clean_table(void);

// philo_time :
t_usec	get_time(void);
void	sleep_ms(t_usec start_time, t_usec stime_ms);

// philo_utils :
int		ft_strcmp(char *string1, char *string2);
void	philo_print(int philo_id, t_usec time, char *msg);
int		philo_atoi(char *string);

#endif /*PHILO_DINER_H*/
