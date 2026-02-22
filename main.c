/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:07:25 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 22:20:28 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main_arg2(char **argv)
{
	int	ec;

	if (ft_strcmp(argv[1], "-") == 0)
	{
		interactive();
	}
	else
	{
		ec = main_next("numbers.dict", argv[1]);
		if (ec)
			print_error(ec);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	ec;

	if (argc == 2)
	{
		main_arg2(argv);
	}
	else if (argc == 3)
	{
		ec = main_next(argv[1], argv[2]);
		if (ec)
			print_error(ec);
	}
	else
	{
		print_error(-1);
		return (1);
	}
	return (0);
}
