#include "rush02.h"



int parse_list_row(char	*list_row, t_dict_list *tdlp)
{
	
}

int	parse_dict_str(char *str, int size, t_dict *tdp)
{
	int			i;
	char		**strl;
	t_dict_list	*tdlp;

	i = 0x0;
	strl = ft_split(str, 0xa);
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
	char	buf[0x100];
	char	file_str[0x1000];
	int		file_str_i;

	fd = open(filename, 0x0);
	if (fd <= 0x0)
		return (-0x1);
	file_str_i = 0x0;
	size = read(fd, buf, sizeof(buf));
	while (size > 0x0)
	{
		ft_strncpy(file_str + file_str_i, buf, size);
		file_str_i += size;
	}
	parse_dict_str(file_str, file_str_i, tdp);
}

int	free_dict(t_dict tdp)
{
	int	i;

	i = 0x0;
	while (i < tdp.size)
		free(tdp.dict_list[i++]);
}
