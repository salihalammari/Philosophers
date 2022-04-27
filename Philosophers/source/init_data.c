/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 02:48:07 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 01:02:01 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_arg(t_arg *arg, int argc, char **argv)
{
	if (!is_num(argv))
		return (EXIT_FAILURE);
	arg->num_of_philo = ft_atoi(argv[1]);
	arg->time_to_die = ft_atoi(argv[2]);
	arg->time_to_eat = ft_atoi(argv[3]);
	arg->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		arg->num_of_must_eat = ft_atoi(argv[5]);
		if (arg->num_of_must_eat <= 0)
			return (EXIT_FAILURE);
	}
	else
		arg->num_of_must_eat = -1;
	if (arg->num_of_philo <= 0 || arg->time_to_die <= 0 || \
		arg->time_to_eat <= 0 || arg->time_to_sleep <= 0)
		return (EXIT_FAILURE);
	arg->num_of_end = 0;
	arg->end = 0;
	return (EXIT_SUCCESS);
}

int	malloc_arg(t_arg *arg)
{
	arg->philo = (t_philo *)malloc(sizeof(t_philo) * arg->num_of_philo);
	if (!arg->philo)
		return (EXIT_FAILURE);
	arg->forks_mutex = \
		(pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * arg->num_of_philo);
	if (!arg->forks_mutex)
	{
		free(arg->philo);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	init_philo(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		arg->philo[i].id = i;
		arg->philo[i].eat_cnt = 0;
		arg->philo[i].last_ate = 0;
		arg->philo[i].is_dead = 0;
		arg->philo[i].arg = arg;
		arg->philo[i].left_fork = i;
		arg->philo[i].right_fork = (i + 1) % arg->num_of_philo;
		i++;
	}
	return (EXIT_SUCCESS);
}

int	init_mutex(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		if (pthread_mutex_init(&arg->forks_mutex[i], NULL) != 0)
			return (EXIT_FAILURE);
		i++;
	}
	if (pthread_mutex_init(&arg->print_mutex, NULL) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
