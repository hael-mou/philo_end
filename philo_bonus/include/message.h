/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:39:24 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/09 20:41:29 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGE_H
# define MESSAGE_H

//Error Message:
# define ALC_ERROR	" 🔸 Allocation Error\n"
# define ARG_ERROR	" 🔸 Non-numeric, Negative-number OR greater than \"INT MAX\"\n"
# define MUTEX_ERROR " 🔸 Mutex Init Error\n"
# define NARG_ERROR	" 🔸 The number of argments must be 4 or 5 use [-help]\
 for more info\n"

// philo routine:
# define THINKING "is thinking\n"
# define SLEEPING "is sleeping\n"
# define TAKING "has taken a fork\n"
# define EATING "is eating\n"

//help menu:
# define HELP "\
 -> The number of argments must be 4 or 5 numeric & positive :\n\
	🔸 First arg	: number of philosophers\n\
	🔸 Second arg	: time to die\n\
	🔸 Third arg	: time to eat\n\
	🔸 Fourth arg	: time to sleep\n\
	🔸 Fifth arg	: number of times each philosopher must eat {optinal}\n"

#endif /* MESSAGE_H */
