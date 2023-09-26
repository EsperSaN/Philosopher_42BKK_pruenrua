#include "philo.h"

int	main(int ac, char **av)
{
	t_var	v;
	int		i;

	i = -1;
	v.begin_epoch_time = get_time();
	if (ac < 5 || ac > 6)
		return (printf(ER_MSG), 1);
	if (!input_checker(av + 1))
		return (printf(INP_MSG), 1);
	if (!init_var(&v, av, ac))
		return (printf(FAIL_INIT), 1);
	while (++i < v.philo_num)
	{
		if (pthread_create(&v.philo[i].philo, NULL, &rout, (void *)&v.philo[i]))
		{
			printf("Error :Thread cant be create\n");
			let_em_free(&v);
			return (1);
		}
	}
	usleep(5);
	mammy_thread_takking_care_of_all_philo(&v);
	i = -1;
	while (++i < v.philo_num)
		pthread_join(v.philo[i].philo, NULL);
	let_em_free(&v);
	return (1);
}