/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:57:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 16:36:29 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nb_value(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (str[0] == ' ')
		while (str[i] == ' ')
			i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			while (str[i] >= '0' && str[i] <= '9')
			{
				i++;
				if (str[i] == ' ' || str[i] == '\0')
					data->nb_value_a++;
			}
		else
			i++;
	}
}

void	loop_split_number(char *str, char *s, int *buff)
{
	int	i;
	int	m;
	int	len_tab;

	len_tab = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		else if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
				|| str[i] == '+')
		{
			m = 0;
			while ((str[i] >= '0' && str[i] <= '9') || str[i] == '-'
				|| str[i] == '+')
				s[m++] = str[i++];
			s[m + 1] = '\0';
			buff[len_tab] = ft_atoi(s);
			len_tab++;
			while (m != 0)
				s[m--] = '\0';
		}
	}
}

int	*split_number(char *str, t_data *data)
{
	int		*buff;
	char	*s;

	nb_value(str, data);
	s = ft_calloc(13, sizeof(int));
	buff = malloc(sizeof(int) * data->nb_value_a);
	loop_split_number(str, s, buff);
	free(str);
	free(s);
	return (buff);
}
