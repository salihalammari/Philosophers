/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 02:39:42 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 20:04:32 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philo.h"

long long	get_time(void)
{
	struct timeval	x;

	gettimeofday(&x, NULL);
	return ((x.tv_sec * 1e3) + (x.tv_usec / 1e3));
}

void	ft_usleep(unsigned long time)
{
	unsigned long	curr;

	curr = get_time();
	while (get_time() - curr < time)
		usleep(50);
}

void	ft_free(t_data *data, int l)
{
	free(data->philos);
	exit(l);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			n;

	i = 0;
	n = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			n = n * 10 + str[i] - 48;
			i++;
		}
		else
			return (-1);
	}
	if (n > 2147483647)
		return (-1);
	return (n);
}
