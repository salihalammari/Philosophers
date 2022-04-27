/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:48 by slammari          #+#    #+#             */
/*   Updated: 2022/04/26 02:46:59 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philo.h"

void	sets_fork(t_philo *philo, int x)
{
	if (x == 0)
	{
		sem_wait(philo->data->forks);
		printf_philo_status(philo, "taken a fork", 1);
		sem_wait(philo->data->forks);
		printf_philo_status(philo, "taken a fork", 1);
	}
	else
	{
		sem_post(philo->data->forks);
		sem_post(philo->data->forks);
	}
}

void	printf_philo_status(t_philo *philo, char *s, int lamp)
{
	sem_wait(philo->data->printf);
	printf("%lld philo %d %s\n", (get_time() - philo->data->time) \
		, philo->index, s);
	if (lamp)
		sem_post(philo->data->printf);
}

void	ft_exit(t_data *data, int *pid, int size)
{
	int	i;
	int	status;

	if (size == data->n_philo)
		return (free(pid), ft_free(data, 0));
	wait(&status);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 1)
		{
			i = -1;
			while (++i < data->n_philo)
				kill(pid[i], SIGKILL);
		}
		else
			return (ft_exit(data, pid, size + 1));
	}
	else
	{
		i = -1;
		while (++i < data->n_philo)
			kill(pid[i], SIGKILL);
	}
	return (free(pid), ft_free(data, 0));
}
