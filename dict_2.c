/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:51:20 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 21:53:06 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	parse_list_row(char *list_row, t_dict_list *tdlp)
{
	char	**number_word;

	if (!list_row || !tdlp)
		return (-1);
	number_word = ft_split(list_row, ":");
	if (!number_word || !number_word[0] || !number_word[1])
	{
		free_str_split(number_word);
		return (-1);
	}
	tdlp->number = skip_spaces(number_word[0]);
	tdlp->word = skip_spaces(number_word[1]);
	free_str_split(number_word);
	return (0);
}

int	parse_dict_str(char *str, int size, t_dict *tdp)
{
	int		i;
	char	**strl;

	if (!tdp || !size)
		return (-1);
	i = 0;
	strl = ft_split(str, "\n");
	if (!strl)
		return (-1);
	while (strl[i])
	{
		if (!parse_list_row(strl[i], tdp->dict_list + tdp->size))
		{
			tdp->size++;
		}
		i += 0x1;
	}
	ft_split_free(strl);
	return (0);
}

int	parse_dict(char *filename, t_dict *tdp)
{
	int		fd;
	int		size;
	char	buf[256];
	char	file_str[4096];
	int		file_str_i;

	fd = open(filename, 0);
	if (fd <= 0)
		return (-1);
	file_str_i = 0;
	size = read(fd, buf, sizeof(buf));
	while (size > 0)
	{
		ft_strncpy(file_str + file_str_i, buf, size);
		file_str_i += size;
		size = read(fd, buf, sizeof(buf));
	}
	return (parse_dict_str(file_str, file_str_i, tdp));
}

void	print_dict(t_dict *tdp)
{
	unsigned int	i;

	i = 0;
	while (i < tdp->size)
	{
		printf("%s: [%s]\n", tdp->dict_list[i].number, tdp->dict_list[i].word);
		i++;
	}
}

int	free_dict(t_dict *tdp)
{
	unsigned int	i;

	i = 0;
	while (i < tdp->size)
	{
		free(tdp->dict_list[i].number);
		free(tdp->dict_list[i].word);
		i++;
	}
	free((tdp->dict_list));
	return (0);
}
