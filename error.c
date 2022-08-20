/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:22:19 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/19 21:56:21 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

int	error_argument(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[0] == ' ')
			while (str[i] == ' ')
			{
				if (str[i] == '\0')
					return (0);
				i++;
			}
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == ' '\
			|| (str[i] == '-' && str[i + 1] >= '0' && str[i] <= '9')\
			|| (str[i] == '+' && str[i + 1] >= '0' && str[i] <= '9'))
			i++;
		else
			return (0);
	}
	return (1);
}

int error_without_space(char *str)
{
	int i;
	int	count_nb;
	int	count_spc;

	i = 0;
	count_nb = 0;
	count_spc = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9'\
			&& (str[i + 1] == ' ' || str[i + 1] == '\0'\
			|| str[i + 1] == '-' || str[i + 1] == '+'))
			count_nb++;
		if (str[i] == ' ')
			count_spc++;
		i++;
	}
	if (count_nb >= 2 && count_spc == 0)
		return (0);
	return (1);
}

int	error_same_nb(int *buff, t_data *data)
{
	int i;
	int m;
	int l;
	int verif[data->nb_value_a];

	i = data->nb_value_a - 1;
	m = 0;
	while (i >= 0)
	{
		verif[m] = buff[i];
		l = i - 1;
		while (l >= 0)
		{
			if (verif[m] == buff[l])
				return (0);
			l--;
		}
		m++;
		i--;
	}
	return (1);
}
