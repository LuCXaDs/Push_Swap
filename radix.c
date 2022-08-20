/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 23:41:44 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 21:17:46 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_loop(int size)
{
	int byte;

	byte = 32;
	while (--byte > 0)
		if (size >> byte & 1)
			break ;
	return (byte);
}

int high_nb(int *index, t_data *data)
{
	int	i;
	int	size;

	i = 0;
	size = index[i];
	while (i < data->nb_value_a)
	{
		if (size < index[i])
			size = index[i];
		i++;
	}
	size = nb_loop(size);
	return (size);
}

void	radix(int *buff_a, int *buff_b, t_data *data)
{
	int i;
	int j;
	int byte;
	int len_fix;
	int *index;

	j = 0;
	len_fix = data->nb_value_a;
	index = index_tab(buff_a, data);
	byte = high_nb(index, data);
	while (j <= byte)
	{
		i = 0;
		while (i < len_fix)
		{
			if ((index[0] >> j) & 1)
				rotate_a(index, data);
			else
				push_b(index, buff_b, data);
			i++;
		}
		while (0 < data->nb_value_b)
			push_a(index, buff_b, data);	
		j++;
	}
	free(index);
}

int *index_tab(int *buff_a, t_data *data)
{
	int	i;
	int	j;
	int	size;
	int	*index;

	j = 0;
	index = malloc(sizeof(int) * data->nb_value_a);
	while (j <= data->nb_value_a - 1)
	{
		size = 1;
		i = 0;
		while (i < data->nb_value_a)
		{
			if (buff_a[i] < buff_a[j])
				size++;
			i++;
		}
		index[j] = size;
		j++;
	}
	return (index);
}