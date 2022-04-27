/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dining.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:05:28 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 01:04:12 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	finished_meal(t_arg *a)
{
	a->end = 1;
	usleep(1000);
	pthread_mutex_lock(&a->print_mutex);
	printf("All philosophers have finished their meals\n");
	pthread_mutex_unlock(&a->print_mutex);
}

void	*routine(void *philo)
{
	t_philo		*p;
	t_arg		*a;

	p = (t_philo *)philo;
	a = p->arg;
	if (p->id % 2 == 0 && a->num_of_philo != 1)
		usleep(1000 * a->time_to_eat);
	while (!a->end)
	{
		taking_forks(p, a);
		eating(p, a);
		if (a->end)
			break ;
		if (a->num_of_must_eat > 0 && a->num_of_end >= a->num_of_philo)
		{
			finished_meal(a);
			break ;
		}
		sleeping(p, a);
		if (a->end)
			break ;
		thinking(p, a);
	}
	return ((void *)EXIT_SUCCESS);
}

void	*monitor(void *philo)
{
	t_arg		*a;
	t_philo		*p;

	p = (t_philo *)philo;
	a = p->arg;
	while (!a->end)
	{
		if (get_time() - p->last_ate >= a->time_to_die)
		{
			a->end = 1;
			pthread_mutex_lock(&a->print_mutex);
			printf("%lld\t", get_time() - p->arg->start_time);
			printf("%d\t%s\t(%d)\n", p->id + 1, "dead", p->eat_cnt);
			return ((void *)EXIT_SUCCESS);
		}
		usleep(100);
	}
	return ((void *)EXIT_SUCCESS);
}

int	dining(t_arg *arg)
{
	int			i;

	i = 0;
	arg->start_time = get_time();
	while (i < arg->num_of_philo)
	{
		arg->philo[i].last_ate = get_time();
		if (pthread_create(&arg->philo[i].philo_tid, \
			NULL, routine, &arg->philo[i]) != 0)
			return (EXIT_FAILURE);
		if (pthread_create(&arg->philo[i].monitor_tid, \
			NULL, monitor, &arg->philo[i]) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_join(arg->philo[i].philo_tid, NULL) != 0)
			return (EXIT_FAILURE);
		if (pthread_join(arg->philo[i].monitor_tid, NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}
