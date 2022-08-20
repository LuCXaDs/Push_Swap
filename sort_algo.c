/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 16:05:05 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/18 21:49:32 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_two_number(int *buff_a)
{
	if (buff_a[0] > buff_a[1])
		swap_a(buff_a);
}

void	algo_three_number(int *buff_a, t_data *data)
{
	if (buff_a[0] > buff_a[1] && buff_a[1] > buff_a[2])
	{
		swap_a(buff_a);
		reverse_rotate_a(buff_a, data);
	}
	if (buff_a[0] < buff_a[1] && buff_a[1] > buff_a[2] && buff_a[2] < buff_a[0])
		reverse_rotate_a(buff_a, data);
	if (buff_a[0] > buff_a[1] && buff_a[1] < buff_a[2] && buff_a[2] > buff_a[0])
		swap_a(buff_a);
	if (buff_a[0] > buff_a[1] && buff_a[1] < buff_a[2] && buff_a[2] < buff_a[0])
	{
		reverse_rotate_a(buff_a, data);
		reverse_rotate_a(buff_a, data);
	}
	if (buff_a[0] < buff_a[1] && buff_a[1] > buff_a[2] && buff_a[2] > buff_a[0])
	{
		reverse_rotate_a(buff_a, data);
		swap_a(buff_a);
	}
}

int	loop_algo_four_five(int *buff_a, t_data *data)
{
	int	i;
	int	lower;
	int	pos;

	
	i = data->nb_value_a - 1;
	pos = i;
	lower = buff_a[i];
	while (i >= 0)
	{
		if (lower > buff_a[i])
		{
			lower = buff_a[i];
			pos = i;
		}
		i--;
	}
	return (pos);
}

void	algo_four_number(int *buff_a, int *buff_b, t_data *data)
{
	int	pos;

	pos = loop_algo_four_five(buff_a, data);
	if (pos == 1)
		swap_a(buff_a);
	else if (pos == 2)
	{
		reverse_rotate_a(buff_a, data);
		reverse_rotate_a(buff_a, data);
	}
	else if (pos == 3)
		reverse_rotate_a(buff_a, data);
	push_b(buff_a, buff_b, data);
	algo_three_number(buff_a, data);
	push_a(buff_a, buff_b, data);
}

void	algo_five_number(int *buff_a, int *buff_b, t_data *data)
{
	int pos;

	pos = loop_algo_four_five(buff_a, data);
	if (pos == 1)
		swap_a(buff_a);
	else if (pos == 2)
	{
		rotate_a(buff_a, data);
		rotate_a(buff_a, data);
	}
	else if (pos == 3)
	{
		reverse_rotate_a(buff_a, data);
		reverse_rotate_a(buff_a, data);
	}
	else if (pos == 4)
		reverse_rotate_a(buff_a, data);
	push_b(buff_a, buff_b, data);
	algo_four_number(buff_a, buff_b, data);
	push_a(buff_a, buff_b, data);
}