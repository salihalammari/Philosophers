/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:04:59 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 01:01:42 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	long long		ret;
	struct timeval	time;

	ret = 0;
	if (gettimeofday(&time, NULL) == -1)
		error_msg("gettimeofday fail");
	ret = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ret);
}

void	print_philo(t_philo *philo, t_arg *arg, char *msg)
{
	if (arg->end)
		return ;
	pthread_mutex_lock(&arg->print_mutex);
	printf("%lld\t", get_time() - philo->arg->start_time);
	printf("%d\t", philo->id + 1);
	printf("%s\t", msg);
	printf("(%d)\n", philo->eat_cnt);
	pthread_mutex_unlock(&arg->print_mutex);
}

void	end_dining(t_arg *arg)
{
	int	i;

	i = 0;
	while (i < arg->num_of_philo)
	{
		pthread_mutex_destroy(&(arg->forks_mutex[i]));
		i++;
	}
	pthread_mutex_destroy(&(arg->print_mutex));
	free(arg->forks_mutex);
	free(arg->philo);
}

int	main(int argc, char **argv)
{
	t_arg			arg;

	if (argc != 5 && argc != 6)
		return (error_msg("Wrong amount of arguments"));
	if (init_arg(&arg, argc, argv))
		return (error_msg("Invalid arguments"));
	if (malloc_arg(&arg))
		return (error_msg("Malloc error"));
	if (init_philo(&arg) || init_mutex(&arg))
		return (error_msg("Initialize error"));
	if (dining(&arg))
		return (error_msg("Thread error"));
	end_dining(&arg);
	return (0);
}
