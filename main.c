/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 16:28:08 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 19:14:21 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*call_split(char *str, t_data *data)
{
	int	*buff_a;

	buff_a = split_number(str, data);
	return (buff_a);
}

void	sort_algo(int *buff_a, int *buff_b, t_data *data)
{
	if (data->nb_value_a == 2)
		algo_two_number(buff_a);
	else if (data->nb_value_a == 3)
		algo_three_number(buff_a, data);
	else if (data->nb_value_a == 4)
		algo_four_number(buff_a, buff_b, data);
	else if (data->nb_value_a == 5)
		algo_five_number(buff_a, buff_b, data);
	else if (data->nb_value_a > 5)
		radix(buff_a, buff_b, data);
	free(buff_a);
	free(buff_b);
}

int	is_already_sort(int *buff_a, t_data *data)
{
	int	i;
	int	nb;
	int	sup;

	i = 0;
	sup = 0;
	while (i <= data->nb_value_a - 2)
	{
		nb = buff_a[i];
		i++;
		if (nb < buff_a[i])
			sup++;
		if (sup == data->nb_value_a - 1)
			return (1);
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_data data;
	int i;
	int *buff_a;
	int *buff_b;
	char *str;

	i = 0;
	data.nb_value_a = 0;
	data.nb_value_b = 0;
	data.ac = ac;
	data.av = av;
	if (ac == 1)
		return (0);
	if (ac >= 2)
	{
		buff_b = ft_calloc(ac, sizeof(int));
		str = ft_calloc(1, sizeof(char));
		while (i++ < data.ac - 1)
		{
			str = ft_strjoin(str, data.av[i]);
			if (error_argument(data.av[i]) == 0)
				return (free(str), free(buff_b), error(), 0);
		}
		// ft_printf("%s", str);
		str = many_space_to_one(str);
		if (error_without_space(str) == 0)
			return (free(str), free(buff_b), error(), 0);
		// ft_printf("%s", str);
		if (verif_len_max_min(str) == 0)
			return (free(str), free(buff_b), error(), 0);
		buff_a = call_split(str, &data);
		if (error_same_nb(buff_a, &data) == 0)
			return (free(buff_a), free(buff_b), error(), 0);
		if (is_already_sort(buff_a, &data) == 1)
			return (free(buff_a), free(buff_b), 0);
		else
			sort_algo(buff_a, buff_b, &data);
	}
	return (0);
}