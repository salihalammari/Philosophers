/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slammari <slammari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:11:50 by slammari          #+#    #+#             */
/*   Updated: 2022/04/27 20:04:59 by slammari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_msg(char *msg)
{
	int			len;

	len = 0;
	while (msg[len])
		len++;
	write(2, "Error:", 6);
	write(1, msg, len);
	write(1, "\n", 1);
	return (1);
}

int	ft_atoi(const char *str)
{
	long		nbr;
	long		sign;
	size_t		i;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if (nbr > 2147483647 && sign == 1)
			return (-1);
		if (nbr > 2147483648 && sign == -1)
			return (0);
	}
	return (nbr * sign);
}

int	is_num(char **argv)
{
	int			i;
	int			j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}
