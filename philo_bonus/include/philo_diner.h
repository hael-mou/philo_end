/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_diner.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 16:22:43 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:13:13 by hael-mou         ###   ########.fr       */
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
# include <semaphore.h>
# include <pthread.h>
# include <signal.h>
# include <limits.h>
# include <sys/wait.h>
# include <sys/time.h>
# include "safe_int.h"
# include "message.h"

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

# define DEAD		5

// typedef :
typedef unsigned long long int	t_usec;

/*###############################################################
#  	   * struct	:												#
###############################################################*/
typedef struct s_philo
{
	int			id;
	pid_t		pid;
	t_safeint	meal_ate;
	t_safeint	last_meal;
	t_safeint	status;
}	t_philo;

// diner table :
typedef struct s_table
{
	int			death_time;
	int			meal_duration;
	int			sleep_duration;
	int			number_of_philo;
	int			meal_count;
	t_philo		*philos;
	sem_t		*forks;
	sem_t		*screen;
}	t_table;

/*###############################################################
#  	   * Functions :											#
###############################################################*/
// check argument :
int		check_arguments(int argc, char **argv);
int		parse_arguments(int argc, char **argv);

//philo process :
int		philo_create(void);
int		wait_process(void);	

//philo routine :
void	routine(t_philo *philo, t_usec start_time);

// philo_checker :
void	thread_scheduler(t_philo *philo);
void	kill_philos(t_philo *philos);

// philo_table :
t_table	*get_table(void);
int		init_table(int argc, char **argv);
void	clean_table(void);

// philo_time :
t_usec	get_time(void);
void	sleep_ms(t_usec start_time, t_usec time);

// philo_utils :
int		ft_strcmp(char *string1, char *string2);
void	philo_print(int philo_id, t_usec time, char *msg);
int		philo_atoi(char *string);
char	*ft_itoa(char *s, int len, int number);

#endif /*PHILO_DINER_H*/
