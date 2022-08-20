/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:01:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 21:09:05 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	add_nb_in_list_a(int *buff_b, t_data *data);

void	swap_a(int *buff_a)
{
	int	temp;

	if (!buff_a[0] || !buff_a[1])
		return ;
	temp = buff_a[0];
	buff_a[0] = buff_a[1];
	buff_a[1] = temp;
	ft_printf("sa\n");
}

void	push_a(int *buff_a, int *buff_b, t_data *data)
{
	int	i;
	int	temp;
	int	temp1;

 	if (!buff_b || !buff_b[0])
		return ;
	data->nb_value_a++;
	data->nb_value_b--;
	temp = buff_b[0];
	add_nb_in_list_a(buff_a, data);
	i = data->nb_value_b - 1;
	buff_a[0] = temp;
	temp = buff_b[data->nb_value_b];
	while (i >= 0)
	{
		temp1 = buff_b[i];
		buff_b[i] = temp;
		temp = temp1;
		i--;
	}
	ft_printf("pa\n");
}

static void	add_nb_in_list_a(int *buff_a, t_data *data)
{
	int	i;
	int	m;
	int	temp;

	i = 0;
	m = 0;
	temp = buff_a[0];
	while (i <= data->nb_value_a - 1)
	{
		temp = buff_a[i];
		buff_a[i] = buff_a[m];
		buff_a[m] = temp;
		i++;
	}
}

void	rotate_a(int *buff_a, t_data *data)
{
	int	temp;
	int	temp1;
	int	m;
	int	i;

	i = data->nb_value_a - 2;
	m = data->nb_value_a - 1;
	temp1 = buff_a[0];
	while (i >= 0)
	{
		temp = buff_a[i];
		buff_a[i] = buff_a[m];
		buff_a[m] = temp;
		i--;
	}
	buff_a[data->nb_value_a - 1] = temp1;
	ft_printf("ra\n");
}

void	reverse_rotate_a(int *buff_a, t_data *data)
{
	int temp;
	int temp1;
	int m;
	int i;

	i = 1;
	m = 0;
	temp1 = buff_a[data->nb_value_a - 1];
	while (i <= data->nb_value_a - 1)
	{
		temp = buff_a[i];
		buff_a[i] = buff_a[m];
		buff_a[m] = temp;
		i++;
	}
	buff_a[0] = temp1;
	ft_printf("rra\n");
}