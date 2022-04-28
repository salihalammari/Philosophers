/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:29 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 20:04:24 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philo.h"

void	ft_sem_init(t_data *data)
{
	sem_unlink("forks");
	sem_unlink("printf");
	data->forks = sem_open("forks", O_CREAT, 0777, data->n_philo);
	data->printf = sem_open("printf", O_CREAT, 0777, 1);
	if (data->forks == SEM_FAILED || data->forks == SEM_FAILED)
		return (free(data->philos), exit(0));
}

void	*ft_procces(void *ph)
{
	t_philo	*philo;

	philo = ph;
	if (!(philo->index & 1))
		ft_usleep(philo->data->t_eat / 2);
	while (1)
	{
		sets_fork(philo, 0);
		printf_philo_status(philo, "is eating", 1);
		ft_usleep(philo->data->t_eat);
		sets_fork(philo, 1);
		philo->last_eat = get_time();
		printf_philo_status(philo, "is sleeping", 1);
		ft_usleep(philo->data->t_sleep);
		printf_philo_status(philo, "is thinking", 1);
		philo->n_eat += 1;
	}
}

int	routine(t_philo *philo)
{
	pthread_t	procces;

	pthread_create(&procces, NULL, ft_procces, philo);
	pthread_detach(procces);
	while (1)
	{
		if (philo->data->n_eat != -1)
		{
			if (philo->n_eat >= philo->data->n_eat)
				ft_free(philo->data, 0);
		}
		if ((get_time() - philo->last_eat) > philo->data->t_die)
		{
			printf_philo_status(philo, "died", 0);
			ft_free(philo->data, 1);
		}
		usleep(50);
	}
}

int	*ft_init_philo(t_data *data)
{
	int	i;
	int	pid;
	int	*pids;

	ft_sem_init(data);
	i = -1;
	pids = malloc(sizeof(int) * data->n_philo);
	while (++i < data->n_philo)
	{
		pid = fork();
		if (pid == 0)
			routine(&data->philos[i]);
		else
			pids[i] = pid;
	}
	return (pids);
}
