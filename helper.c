/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:09:05 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 22:09:07 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	print_error(int error_code)
{
	if (error_code == 0)
		return (-1);
	if (error_code < -1)
		write(1, "Dict Error\n", 11);
	else
		write(1, "Error\n", 6);
	return (0);
}

int	parse_num_str(char **num_str)
{
	char	*new_str;
	int		i;

	new_str = skip_spaces_num(*num_str);
	*num_str = new_str;
	i = 0;
	while (new_str[i])
	{
		if (new_str[i] < '0' || new_str[i] > '9')
			return (-1);
		i++;
	}
	return (0);
}
