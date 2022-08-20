/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 17:01:21 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 20:53:47 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_nb_in_list_b(int *buff_b, t_data *data);

void	swap_b(int *buff_b)
{
	int	temp;

	if (!buff_b[0] || !buff_b[1])
		return ;
	temp = buff_b[0];
	buff_b[0] = buff_b[1];
	buff_b[1] = temp;
	ft_printf("sb\n");
}

void	rotate_b(int *buff_b, t_data *data)
{
	int	temp;
	int	temp1;
	int	m;
	int	i;

	i = data->nb_value_a - 2;
	m = data->nb_value_a - 1;
	temp1 = buff_b[0];
	while (i >= 0)
	{
		temp = buff_b[i];
		buff_b[i] = buff_b[m];
		buff_b[m] = temp;
		i--;
	}
	buff_b[data->nb_value_a - 1] = temp1;
	ft_printf("rb\n");
}

void	reverse_rotate_b(int *buff_b, t_data *data)
{
	int	temp;
	int	temp1;
	int	m;
	int	i;

	i = 1;
	m = 0;
	temp1 = buff_b[data->nb_value_a - 1];
	while (i <= data->nb_value_a - 1)
	{
		temp = buff_b[i];
		buff_b[i] = buff_b[m];
		buff_b[m] = temp;
		i++;
	}
	buff_b[0] = temp1;
	ft_printf("rrb\n");
}

void	push_b(int *buff_a, int *buff_b, t_data *data)
{
	int	i;
	int	temp;
	int	temp1;

	if (!buff_a[0])
		return ;
	data->nb_value_b++;
	data->nb_value_a--;
	temp = buff_a[0];
	add_nb_in_list_b(buff_b, data);
	i = data->nb_value_a - 1;
	buff_b[0] = temp;
	temp = buff_a[data->nb_value_a];
	while (i >= 0)
	{
		temp1 = buff_a[i];
		buff_a[i] = temp;
		temp = temp1;
		i--;
	}
	ft_printf("pb\n");
}

void	add_nb_in_list_b(int *buff_b, t_data *data)
{
	int i;
	int m;
	int temp;

	i = 0;
	m = 0;
	temp = buff_b[0];
	while (i <= data->nb_value_b - 1)
	{
		temp = buff_b[i];
		buff_b[i] = buff_b[m];
		buff_b[m] = temp;
		i++;
	}
}