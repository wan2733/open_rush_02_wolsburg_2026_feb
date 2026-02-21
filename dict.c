#include "rush02.h"

char	*skip_spaces(char *list_row)
{
	while (*list_row == ' ' || *list_row == '\t'
		|| *list_row == '\v' || *list_row == '\f' || *list_row == '\r')
		list_row++;
	return (list_row);
}

int	parse_list_row(char *list_row, t_dict_list *tdlp)
{
	int			i;
	long long	nb;

	nb = 0;
	list_row = skip_spaces(list_row);
	if (*list_row < '0' || *list_row > '9')
		return (-1);
	while (*list_row >= '0' && *list_row <= '9')
		nb = nb * 10 + (*list_row++ - '0');
	tdlp->number = malloc(sizeof(long long));
	if (!tdlp->number)
		return (-1);
	*tdlp->number = nb;
	list_row = skip_spaces(list_row);
	if (*list_row != ':')
		return (-1);
	list_row++;
	list_row = skip_spaces(list_row);
	i = 0;
	while (list_row[i] && list_row[i] != '\n')
		i++;
	tdlp->word = malloc(sizeof(char) * (i + 1));
	if (!tdlp->word)
		return (-1);
	i = 0;
	while (*list_row && *list_row != '\n')
		tdlp->word[i++] = *list_row++;
	tdlp->word[i] = '\0';
	return (0);
}

int	parse_dict_str(char *str, int size, t_dict *tdp)
{
	int		i;
	int		count;
	char	**strl;

	if (!tdp || size <= 0)
		return (-1);
	strl = ft_split(str, 10);
	if (!strl)
		return (-1);
	count = 0;
	while (strl[count])
		count++;
	tdp->dict_list = malloc(sizeof(t_dict_list) * count);
	if (!tdp->dict_list)
		return (-1);
	tdp->size = 0;
	i = 0;
	while (strl[i])
	{
		if (parse_list_row(strl[i], &tdp->dict_list[tdp->size]) == 0)
			tdp->size++;
		free(strl[i]);
		i++;
	}
	free(strl);
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
		size = read(fd, buf, sizeof(buf));
		file_str_i += size;
	}
	parse_dict_str(file_str, file_str_i, tdp);
	return (0);
}

int	free_dict(t_dict tdp)
{
	unsigned int	i;

	i = 0;
	while (i < tdp.size)
	{
		free(tdp.dict_list[i].number);
		free(tdp.dict_list[i].word);
		i++;
	}
	free(tdp.dict_list);
	return (0);
}
