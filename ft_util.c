/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/21 11:25:25 by jdenaux           #+#    #+#             */
/*   Updated: 2026/02/22 18:03:23 by shteng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	free_str_split(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*ft_strdup(char *str)
{
	char	*dest;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (str[len])
		len++;
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*str_dup_malloc(char *s1, char *sep, char *s2)
{
	char	*result;
	int		len1;
	int		selen;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	selen = ft_strlen(sep);
	len2 = ft_strlen(s2);
	result = malloc(len1 + selen + len2 + 1);
	if (!result)
		return (0);
	i = 0;
	while (*s1)
		result[i++] = *s1++;
	while (*sep)
		result[i++] = *sep++;
	while (*s2)
		result[i++] = *s2++;
	result[i] = '\0';
	return (result);
}

int	ft_atoi(char *str, long long *value)
{
	long long	res;
	int			i;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	*value = (res * sign);
	return (0);
}
