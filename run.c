/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:32:09 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 21:32:38 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	find_in_dict(t_dict *dict, char *num_str, int *index)
{
	int	i;

	i = dict->size - 1;
	while (i >= 0)
	{
		if (ft_str_num_cmp(dict->dict_list[i].number, num_str) <= 0)
		{
			*index = i;
			return (0);
		}
		i--;
	}
	return (-1);
}

int	init_run_vars(char **prefix, char **suffix)
{
	*prefix = malloc(1);
	*suffix = malloc(1);
	if (!(*prefix) || !(*suffix))
		return (1);
	(*prefix)[0] = '\0';
	(*suffix)[0] = '\0';
	return (0);
}

void	handle_recursion(char *num, t_dict *dict, char **res, char **vars)
{
	char	*new_res;
	char	*q;
	char	*rem;

	q = vars[0];
	rem = vars[1];
	if (rem[0] != '0')
	{
		if (!run(rem, dict, &vars[3]))
		{
			new_res = str_dup_malloc(*res, " ", vars[3]);
			free(*res);
			*res = new_res;
		}
	}
	if (ft_strlen(num) > 2 && q && ft_strcmp(q, "0") != 0)
	{
		if (!run(q, dict, &vars[2]))
		{
			new_res = str_dup_malloc(vars[2], " ", *res);
			free(*res);
			*res = new_res;
		}
	}
}

int	run(char *num, t_dict *dict, char **result)
{
	int		idx;
	char	*vars[4];
	char	*new_res;

	if (init_run_vars(&vars[2], &vars[3]) || find_in_dict(dict, num, &idx))
		return (-1);
	if (ft_strcmp(num, "0") == 0 || ft_strcmp(num, "1") == 0)
	{
		new_res = str_dup_malloc(*result, "", dict->dict_list[idx].word);
		free(*result);
		*result = new_res;
		return (free(vars[2]), free(vars[3]), 0);
	}
	divide_big_ints(num, dict->dict_list[idx].number, &vars[0], &vars[1]);
	new_res = str_dup_malloc(*result, "", dict->dict_list[idx].word);
	free(*result);
	*result = new_res;
	handle_recursion(num, dict, result, vars);
	free(vars[0]);
	free(vars[1]);
	free(vars[2]);
	free(vars[3]);
	return (0);
}
