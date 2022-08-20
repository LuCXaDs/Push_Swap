/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 23:00:13 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 17:56:45 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*many_space_to_one(char *str)
{
	int		i;
	int		m;
	char	*s;

	i = 0;
	m = 0;
	s = malloc(sizeof(char) * ft_strlen_int(str) + 1);	
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			s[m++] = str[i];
            while (str[i] == ' ')
			{
				i++;
				if (str[i + 1] == '\0')
					break ;
			}
		}
		s[m++] = str[i++];
	}
	s[m++] = '\0';
	return (free(str), s);
}
 
int	verif_len_max_min(char *str)
{
	int		i;
	char	**tab;

	tab = ft_split(str, ' ');
	i = 0;
	while (tab[i])
	{
		if (ft_atol(tab[i]) == 1)
			free(tab[i]);
		else
		{
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free(tab);
			return (0);
		}
		i++;
	}
	free(tab);
	return (1);
}

int	ft_atol(char *nptr)
{
	long int result;
	long int i;
	long int c;

	i = 0;
	result = 0;
	c = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			c = -1;
		if (++result > 1)
			return (0);
	}
	result = 0;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = (nptr[i] - 48) + (result * 10);
		if (result * c < INT_MIN || result * c > INT_MAX)
			return (0);
		i++;
	}
	return (1);
}
