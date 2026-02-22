#include "rush02.h"

int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f');
}

char	*skip_spaces(char *list_row)
{
	int j;

	j = 0;
	
	while (is_space(*list_row))
		list_row++;
	while (list_row[j])
		j++;
	while (list_row[j] && is_space(list_row[j]))
		j--;
	if (list_row[j])
		list_row[j] = 0;
	return ft_strdup(list_row);
}

int	parse_list_row(char	*list_row, t_dict_list *tdlp)
{
	if (!list_row || !tdlp)
		return (-1);
	char **number_word = ft_split(list_row, ":");
	
	if (!number_word || !number_word[0] || !number_word[1])
	{
		free_str_split(number_word);
		return (-1);
	}
	tdlp->number = skip_spaces(number_word[0]);
	tdlp->word = skip_spaces(number_word[1]);
	free_str_split(number_word);
	return 0;
}

int	parse_dict_str(char *str, int size, t_dict *tdp)
{
	int			i;
	char		**strl;

	if (!tdp || !size)
		return -1;

	i = 0;
	strl = ft_split(str, "\n");
	
	while (strl[i])
	{
		//printf("ck0:%s\n", strl[i]);
		if (!parse_list_row(strl[i], tdp->dict_list + tdp->size))
		{
			//printf("ck1 %s: %s\n", tdp->dict_list[tdp->size].number, tdp->dict_list[tdp->size].word);
			tdp->size++;
		}
		
		i += 0x1;
	}
	return 0;
}

//ck0:1000000000000000000000: sextillion
//    9223372036854775807LL

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
	return parse_dict_str(file_str, file_str_i, tdp);
}

int	free_dict(t_dict *tdp)
{
	free((tdp->dict_list));
	return 0;
}
