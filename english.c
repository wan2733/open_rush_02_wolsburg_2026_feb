/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   english.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:51:37 by shteng            #+#    #+#             */
/*   Updated: 2026/02/22 22:19:06 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_word(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 2] == 't' && str[len - 1] == 'y')
		return (1);
	else if (str[len - 2] == 'e' && str[len - 1] == 'd')
		return (1);
	else if (str[len - 2] == 'n' && str[len - 1] == 'd')
		return (1);
	else if (str[len - 2] == 'o' && str[len - 1] == 'n')
		return (1);
	return (0);
}

int	english_post_process(char **str)
{
	char	**words;
	int		i;
	int		n;

	words = ft_split(str[0], " ");
	n = 0;
	while (words[n])
		n++;
	i = 0;
	while (words[i])
	{
		ft_putstr(words[i]);
		if (!check_word(words[i]) && i != (n - 1))
			ft_putstr(" ");
		if (check_word(words[i]) && i != (n - 1))
		{
			if (i == n - 2)
				ft_putstr(" and ");
			else
				ft_putstr(", ");
		}
		i++;
	}
	ft_split_free(words);
	return (0);
}
