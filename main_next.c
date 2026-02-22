/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_next.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 22:07:25 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 22:15:16 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	main_next_1(t_dict *td, char *num_str)
{
	char	*r;
	char	**result;

	sort_dict(td);
	r = malloc(1);
	if (!r)
	{
		free_dict(td);
		free(num_str);
		return (-1);
	}
	r[0] = 0;
	result = &r;
	run(num_str, td, result);
	english_post_process(result);
	free(r);
	free_dict(td);
	free(num_str);
	return (0);
}

int	main_next(char *dict_file_name, char *num_str)
{
	t_dict	td;

	td.dict_list = malloc(sizeof(t_dict_list) * 4096);
	if (!td.dict_list)
		return (-1);
	td.size = 0;
	if (parse_num_str(&num_str))
	{
		free_dict(&td);
		free(num_str);
		return (-1);
	}
	if (parse_dict(dict_file_name, &td))
	{
		free_dict(&td);
		free(num_str);
		return (-2);
	}
	main_next_1(&td, num_str);
	return (0);
}
