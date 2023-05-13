/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:24:24 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/10 18:21:55 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe_int.h"

t_lint	set_safeint_value(t_safeint *safeint, t_lint value)
{
	pthread_mutex_lock(&safeint->lock);
	safeint->value = value;
	pthread_mutex_unlock(&safeint->lock);
	return (value);
}

t_lint	get_safeint_value(t_safeint *safeint)
{
	t_lint	value;

	pthread_mutex_lock(&safeint->lock);
	value = safeint->value;
	pthread_mutex_unlock(&safeint->lock);
	return (value);
}
