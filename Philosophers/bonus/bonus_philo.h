/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:37 by slammari          #+#    #+#             */
/*   Updated: 2022/04/26 02:46:26 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_PHILO_H
# define BONUS_PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct s_philo
{
	pthread_t		philo;
	long long		last_eat;
	int				index;
	int				n_eat;
	struct s_data	*data;
}	t_philo;

typedef struct s_data
{
	long long			time;
	int					n_philo;
	int					t_die;
	int					t_eat;
	int					t_sleep;
	int					n_eat;
	t_philo				*philos;
	sem_t				*printf;
	sem_t				*forks;
}	t_data;

void		ft_exit(t_data *data, int *pid, int size);
void		printf_philo_status(t_philo *philo, char *s, int lamp);
void		sets_fork(t_philo *philo, int x);
int			ft_atoi(const char *str);
void		ft_free(t_data *data, int l);
void		ft_usleep(unsigned long time);
long long	get_time(void);
int			*ft_init_philo(t_data *data);
int			routine(t_philo *philo);
void		*ft_procces(void *ph);
void		ft_sem_init(t_data *data);
int			check_args(int ac, char **av);
void		get_args(t_data *data, char **av, int ac);
int			ft_init(t_data *data);
#endif