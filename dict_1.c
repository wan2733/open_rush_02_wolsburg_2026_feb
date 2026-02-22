/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:51:20 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 21:53:05 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

char	*skip_spaces_num(char *list_row)
{
	int	j;

	j = 0;
	while (is_space(*list_row) || (*list_row == '0' && *(list_row + 1) != 0))
		list_row++;
	while (list_row[j])
		j++;
	while (list_row[j] && is_space(list_row[j]))
		j--;
	if (list_row[j])
		list_row[j] = 0;
	return (ft_strdup(list_row));
}

char	*skip_spaces(char *list_row)
{
	int	j;

	j = 0;
	while (is_space(*list_row))
		list_row++;
	while (list_row[j])
		j++;
	while (list_row[j] && is_space(list_row[j]))
		j--;
	if (list_row[j])
		list_row[j] = 0;
	return (ft_strdup(list_row));
}
