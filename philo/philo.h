#ifndef PHILO_H
# define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <limits.h>
#include <stdint.h>

# define ER_MSG "This program accept only 4 to 5 argument\n"
# define INP_MSG "Please put the correct argument [ONLY POSITIVE INT NUMBER]\n"
# define FAIL_INIT "Fail to init the value SRY\n"
# define INIT_S_ER "Fail to init the main struct\n"

typedef struct s_philo {
	pthread_t		philo;
	pthread_mutex_t	*print_lock;
	pthread_mutex_t	*spoon_left;
	pthread_mutex_t	*spoon_right;
	int				no;
	int				*is_die;
	long			begin_time;
	long			last_eat_time;
	long			p_time;
	long			die_time;
	long			eat_time;
	long			eat_count;
	long			sleep_time;
}	t_philo;

typedef struct s_variable {
	pthread_mutex_t		*print_lock;
	pthread_mutex_t		*all_spoon;
	struct s_philo		*philo;
	long				philo_num;
	long				die_time;
	long				eat_time;
	long				think_time;
	long				sleep_time;
	long				eat_count;
	long				begin_epoch_time;
	int					*is_die;
}	t_var;

void	*ft_calloc(size_t count, size_t size);
int		is_all_num(char *str);
long	ft_atoi(const char *str);
void	let_em_free(t_var *v);
size_t	get_time(void);
int		input_checker(char **arg);
int		init_var(t_var *var, char **av, int ac);
void	mammy_thread_takking_care_of_all_philo(t_var *v);
void	die_check(t_philo *p);
long	dif_time(long time);
void	*rout(void *av);
#endif