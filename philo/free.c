#include "philo.h"

void	nfree(void *p)
{
	free(p);
	p = NULL;
}

void	let_em_free(t_var *v)
{
	int	i;

	if (v->is_die)
		nfree(v->is_die);
	if (v->philo)
		nfree(v->philo);
	if (v->all_spoon)
	{
		i = -1;
		while (++i < v->philo_num)
			pthread_mutex_destroy(&v->all_spoon[i]);
		nfree(v->all_spoon);
	}
	if (v->print_lock)
	{
		pthread_mutex_destroy(v->print_lock);
		nfree(v->print_lock);
	}
}