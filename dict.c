#include "rush02.h"



int parse_list_row(char	*list_row, t_dict_list *tdlp)
{
	int	i;

	while ()
}

int	parse_dict_str(char *str, int size, t_dict *tdp)
{
	int			i;
	char		**strl;
	t_dict_list	*tdlp;

	i = 0;
	strl = ft_split(str, 10);
	tdlp = malloc(sizeof(t_dict_list));
	while (strl[i])
	{
		if (parse_list_row(strl[i], tdlp))
		{
			//tdp->dict_list[tdp->size++] = tdlp;
		}
		tdlp = malloc(sizeof(t_dict_list));
	}
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
}

int	free_dict(t_dict tdp)
{
	int	i;

	i = 0;
	while (i < tdp.size)
		free(tdp.dict_list[i++]);
}
