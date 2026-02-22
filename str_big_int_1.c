/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_big_int_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:30:04 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 21:47:40 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	divide_big_ints_1(char *dividend, char *divisor, char **qcqs, int *nqiiclc)
{
	if (ft_strcmp(divisor, "0") == 0)
		return (1);
	nqiiclc[0] = ft_strlen(dividend);
	qcqs[0] = malloc(nqiiclc[0] + 1);
	qcqs[1] = calloc(nqiiclc[0] + 2, sizeof(char));
	if (!qcqs[0] || !qcqs[1])
	{
		free(qcqs[0]);
		free(qcqs[1]);
		return (-1);
	}
	nqiiclc[1] = 0;
	nqiiclc[2] = 0;
	return (0);
}

int	divide_big_ints_2(char **qcqs, int *nqiiclc,
	char **quotient, char **remainder)
{
	qcqs[0][nqiiclc[1]] = '\0';
	qcqs[2] = qcqs[0];
	while (*qcqs[2] == '0' && *(qcqs[2] + 1) != '\0')
		qcqs[2]++;
	*quotient = ft_strdup(qcqs[2]);
	*remainder = ft_strdup(qcqs[1]);
	free(qcqs[0]);
	free(qcqs[1]);
	if (!*quotient || !*remainder)
		return (-1);
	return (0);
}

int	divide_big_ints(char *dividend, char *divisor, char **quotient,
		char **remainder)
{
	int		nqiiclc[5];
	char	*qcqs[3];

	if (divide_big_ints_1(dividend, divisor, qcqs, nqiiclc))
		return (-1);
	while (nqiiclc[2] < nqiiclc[0])
	{
		nqiiclc[3] = ft_strlen(qcqs[1]);
		qcqs[1][nqiiclc[3]] = dividend[nqiiclc[2]];
		qcqs[1][nqiiclc[3] + 1] = '\0';
		while (qcqs[1][0] == '0' && qcqs[1][1] != '\0')
			ft_strncpy(qcqs[1], qcqs[1] + 1, strlen(qcqs[1]));
		nqiiclc[4] = 0;
		while (is_greater_equal(qcqs[1], divisor))
		{
			subtract_strings(qcqs[1], divisor);
			nqiiclc[4]++;
		}
		qcqs[0][nqiiclc[1]++] = nqiiclc[4] + '0';
		nqiiclc[2]++;
	}
	if (divide_big_ints_2(qcqs, nqiiclc, quotient, remainder))
		return (-1);
	return (0);
}

void	subtract_strings(char *s1, char *s2)
{
	int	i;
	int	j;
	int	leading;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	ss_helper(i, j, s1, s2);
	leading = 0;
	while (s1[leading] == '0' && s1[leading + 1] != '\0')
		leading++;
	if (leading > 0)
		ft_strncpy(s1, s1 + leading, ft_strlen(s1) - leading + 1);
}
