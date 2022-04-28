/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:23 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 20:04:21 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philo.h"

int	main(int ac, char **av)
{
	t_data	data;
	int		*pid;

	if (check_args(ac, av) == -1)
		return (1);
	get_args(&data, av, ac);
	if (ft_init(&data) == -1)
		return (1);
	pid = ft_init_philo(&data);
	sem_close(data.printf);
	sem_close(data.forks);
	ft_exit(&data, pid, 0);
}
