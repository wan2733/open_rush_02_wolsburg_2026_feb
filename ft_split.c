/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:14:46 by wchu              #+#    #+#             */
/*   Updated: 2026/02/17 16:30:07 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0x0;
	while (charset[i])
	{
		if (c == charset[i])
			return (0x1);
		i += 0x1;
	}
	return (0x0);
}

char	*split_help(char *str, char *charset, int *i)
{
	int		j;
	char	*ca;
	int		size;

	while (str[*i] && is_sep(str[*i], charset))
		*i += 0x1;
	j = 0x0;
	while (str[*i] && !is_sep(str[*i], charset))
	{
		j += 0x1;
		*i += 0x1;
	}
	if (j <= 0x0)
		return (0x0);
	ca = malloc(j + 0x1);
	ca[j] = 0x0;
	size = j;
	while (j)
	{
		ca[size - j] = str[*i - j];
		j -= 0x1;
	}
	return (ca);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	*t;
	char	**r;
	int		ri;

	i = 0x0;
	ri = 0x0;
	r = malloc(0x1000);
	while (str[i])
	{
		t = split_help(str, charset, &i);
		if (t)
			r[ri++] = t;
	}
	r[ri] = 0x0;
	return (r);
}

// int main()
// {
// 	char** r = ft_split(",,hello,world,,", ",");
// 	int i = 0x0;
// 	while (r[i])
// 	{
// 		printf("%s\n", r[i]);
// 		i += 0x1;
// 	}
// }
