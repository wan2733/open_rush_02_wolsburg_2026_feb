/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 11:14:46 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 13:53:33 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i += 1;
	}
	return (0);
}

char	*split_help(char *str, char *charset, int *i)
{
	int		j;
	char	*ca;
	int		size;

	while (str[*i] && is_sep(str[*i], charset))
		*i += 1;
	j = 0;
	while (str[*i] && !is_sep(str[*i], charset))
	{
		j += 1;
		*i += 1;
	}
	if (j <= 0)
		return (0);
	ca = malloc(j + 1);
	ca[j] = 0;
	size = j;
	while (j)
	{
		ca[size - j] = str[*i - j];
		j -= 1;
	}
	return (ca);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	*t;
	char	**r;
	int		ri;

	i = 0;
	ri = 0;
	r = malloc(4096);
	while (str[i])
	{
		t = split_help(str, charset, &i);
		if (t)
			r[ri++] = t;
	}
	r[ri] = 0;
	return (r);
}

int	ft_split_free(char **splited_str)
{
	int i;

	i = 0;
	while (splited_str[i])
		free(splited_str[i++]);
	free(splited_str);
	return 0;
}

// int main()
// {
// 	char** r = ft_split(",,hello,world,,", ",");
// 	int i = 0;
// 	while (r[i])
// 	{
// 		printf("%s\n", r[i]);
// 		i += 1;
// 	}
// }
