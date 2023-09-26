#include "philo.h"

long	mins_ab_value(long x, long y)
{
	long	res;

	res = x - y;
	if (res < 0)
		return (res * -1);
	else
		return (res);
}

size_t	get_time(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return ((t.tv_sec * 1000) + (t.tv_usec / 1000));
}

long	dif_time(long time)
{
	return (get_time() - time);
}

void	die_check(t_philo *p)
{
	if (dif_time(p->last_eat_time) > p->die_time)
	{
		pthread_mutex_lock(p->print_lock);
		if (*p->is_die == 0)
			printf("%lu    %d    died\n", dif_time(p->begin_time), p->no);
		*p->is_die = 1;
		pthread_mutex_unlock(p->print_lock);
	}
}

void	mammy_thread_takking_care_of_all_philo(t_var *v)
{
	int	i;

	i = 0;
	while (*v->is_die == 0)
	{
		usleep(1);
		if (i == v->philo_num)
			i = 0;
		die_check(&v->philo[i]);
		i++;
	}
}