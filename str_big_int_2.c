/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_big_int_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:29:53 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 21:29:53 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_greater_equal(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (1);
	if (len1 < len2)
		return (0);
	return (ft_strcmp(s1, s2) >= 0);
}

void	ss_helper(int i, int j, char *s1, char *s2)
{
	int	b;
	int	d;
	int	v1;
	int	v2;

	b = 0;
	while (i >= 0)
	{
		v1 = s1[i] - '0';
		if (j >= 0)
			v2 = s2[j] - '0';
		else
			v2 = 0;
		d = v1 - v2 - b;
		if (d < 0)
		{
			d += 10;
			b = 1;
		}
		else
			b = 0;
		s1[i--] = d + '0';
		j--;
	}
}
