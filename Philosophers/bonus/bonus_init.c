/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:13 by slammari          #+#    #+#             */
/*   Updated: 2022/04/26 02:47:40 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philo.h"

int	check_args(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("invalide arguments !\n");
		return (-1);
	}
	ac = 1;
	while (av[ac])
	{
		if (ft_atoi(av[ac]) <= 0)
		{
			printf("invalide arguments !\n");
			return (-1);
		}
		ac++;
	}
	return (1);
}

void	get_args(t_data *data, char **av, int ac)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	if (ac == 6)
		data->n_eat = ft_atoi(av[5]);
	else
		data->n_eat = -1;
	data->t_sleep = ft_atoi(av[4]);
}

int	ft_init(t_data *data)
{
	int	i;

	i = -1;
	data->philos = malloc(sizeof(t_philo) * (data->n_philo));
	if (!data->philos)
		return (printf("malloc error !\n"), 0);
	data->time = get_time();
	while (++i < data->n_philo)
	{
		data->philos[i].index = i + 1;
		data->philos[i].last_eat = data->time;
		data->philos[i].n_eat = 0;
		data->philos[i].data = data;
	}
	return (1);
}
