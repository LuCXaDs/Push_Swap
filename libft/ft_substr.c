/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luserbu <luserbu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:09:30 by luserbu           #+#    #+#             */
/*   Updated: 2022/08/20 16:26:31 by luserbu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*last_tab(const char *s, unsigned int start, size_t len, char *str);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		str = malloc(sizeof(char) * 1);
		*str = '\0';
		return (str);
	}
	if (len >= ft_strlen(s))
		len = ft_strlen(s) - start;
	str = (char *)malloc(sizeof (*s) * (len + 1));
	if (!str)
		return (NULL);
	str = last_tab(s, start, len, str);
	return (str);
}

char	*last_tab(const char *s, unsigned int start, size_t len, char *str)
{
	size_t	i;
	size_t	si;

	si = 0;
	i = 0;
	while (s[i])
	{
		if (i >= (size_t)start && si < len)
		{
			str[si] = s[i];
			si++;
		}
		i++;
	}
	str[si] = '\0';
	return (str);
}
