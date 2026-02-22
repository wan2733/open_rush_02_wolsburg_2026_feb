/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shteng <shteng@student.42wolfsburg.de      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 18:06:25 by shteng            #+#    #+#             */
/*   Updated: 2026/02/22 18:07:58 by shteng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	interactive(void)
{
	char	buffer[1024];
	int		size;

	while (1)
	{
		size = read(0, buffer, sizeof(buffer));
		buffer[size - 1] = 0;
		if (main_next("numbers.dict", buffer))
			print_error(-1);
		else
			write(1, "\n", 1);
	}
}
