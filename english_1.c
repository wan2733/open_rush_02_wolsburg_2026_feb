/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   english_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:51:37 by shteng            #+#    #+#             */
/*   Updated: 2026/02/22 22:26:25 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	check_med_nbr(char *str)
{
	if (ft_strcmp(str, "million") == 0)
		return (4);
	else if (ft_strcmp(str, "billion") == 0)
		return (5);
	else if (ft_strcmp(str, "trillion") == 0)
		return (6);
	else if (ft_strcmp(str, "quadrillion") == 0)
		return (7);
	else if (ft_strcmp(str, "quintillion") == 0)
		return (8);
	else if (ft_strcmp(str, "sextillion") == 0)
		return (9);
	return (0);
}

int	check_big_nbr(char *str)
{
	if (ft_strcmp(str, "septillion") == 0)
		return (10);
	else if (ft_strcmp(str, "octillion") == 0)
		return (11);
	else if (ft_strcmp(str, "nonillion") == 0)
		return (12);
	else if (ft_strcmp(str, "decillion") == 0)
		return (13);
	else if (ft_strcmp(str, "undecillion") == 0)
		return (14);
	else if (ft_strcmp(str, "duodecillion") == 0)
		return (15);
	else if (ft_strcmp(str, "tredecillion") == 0)
		return (16);
	else if (ft_strcmp(str, "quattuordecillion") == 0)
		return (17);
	else if (ft_strcmp(str, "quindecillion") == 0)
		return (18);
	return (0);
}

int	check_word(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 2] == 't' && str[len - 1] == 'y')
		return (1);
	else if (str[len - 2] == 'e' && str[len - 1] == 'd')
		return (2);
	else if (str[len - 2] == 'n' && str[len - 1] == 'd')
		return (3);
	else if (check_med_nbr(str) > 0)
		return (check_med_nbr(str));
	else if (check_big_nbr(str) > 0)
		return (check_big_nbr(str));
	return (0);
}

int	*check_n_max(char **words, int ans[])
{
	int	n;
	int	chk;

	n = 0;
	chk = 0;
	while (words[n])
	{
		if (check_word(words[n]) > chk)
			chk = check_word(words[n]);
		n++;
	}
	ans[0] = n;
	ans[1] = chk;
	return (ans);
}
