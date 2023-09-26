/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruenrua <pruenrua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 17:31:28 by pruenrua          #+#    #+#             */
/*   Updated: 2023/09/26 20:14:01 by pruenrua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	dif_current_time(long time)
{
	return (get_time() - time);
}

void	die_check(t_philo *p)
{
	if (dif_current_time(p->last_eat_time) > p->die_time)
	{
		pthread_mutex_lock(p->print_lock);
		if (check_state(p) == ALIVE)
			printf("%lu    %d  died\n", dif_current_time(p->begin_time), p->no);
		{
			pthread_mutex_lock(p->c_status);
			*p->status = DIE;
			pthread_mutex_unlock(p->c_status);
		}
		pthread_mutex_unlock(p->print_lock);
	}
}

int	check_state_var(t_var *v)
{
	int	state;

	pthread_mutex_lock(v->c_status);
	state = *v->status;
	pthread_mutex_unlock(v->c_status);
	return (state);
}

void	mammy_thread_takking_care_of_all_philo(t_var *v)
{
	int	i;

	i = 0;
	while (check_state_var(v) == ALIVE)
	{
		usleep(1);
		if (i == v->philo_num)
			i = 0;
		die_check(&v->philo[i]);
		i++;
	}
}
