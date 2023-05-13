/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hael-mou <hael-mou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 09:24:24 by hael-mou          #+#    #+#             */
/*   Updated: 2023/05/13 12:38:00 by hael-mou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "safe_int.h"
#include <stdio.h>

t_lint	set_safeint_value(t_safeint *safeint, t_lint value)
{
	sem_wait(safeint->lock);
	safeint->value = value;
	sem_post(safeint->lock);
	return (value);
}

t_lint	get_safeint_value(t_safeint *safeint)
{
	t_lint	value;

	sem_wait(safeint->lock);
	value = safeint->value;
	sem_post(safeint->lock);
	return (value);
}
