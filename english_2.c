/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   english_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 20:51:37 by shteng            #+#    #+#             */
/*   Updated: 2026/02/22 22:29:54 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	english_post_process_1(char **words, int *ans)
{
	int		i;

	i = 0;
	while (words[i])
	{
		ft_putstr(words[i]);
		if (check_word(words[i]) && i != (ans[0] - 1))
		{
			if (i == ans[0] - 2)
				ft_putstr(" and ");
			else if (check_word(words[i]) == ans[1])
			{
				ft_putstr(", ");
				ans[1]--;
			}
			else
				ft_putstr(" ");
		}
		else if (i != ans[0] - 1)
			ft_putstr(" ");
		i++;
	}
	return (0);
}

int	english_post_process(char **str)
{
	char	**words;
	int		ans[2];

	check_n_max(words = ft_split(str[0], " "), ans);
	english_post_process_1(words, ans);
	ft_split_free(words);
	return (0);
}
