#include "rush02.h"

void	ft_sort_int_tab(int size, char **tab)
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < size)
	{
		key = tab[i];
		j = i - 1;
		while (j >= 0 && ft_str_num_cmp(tab[j], key) > 0)
		{
			tab[j + 1] = tab[j];
			j = j - 1;
		}
		tab[j + 1] = key;
		i += 1;
	}
}

int sort_dict(t_dict *dict)
{
	unsigned int	i;
	int	j;
	char	*key_num;
	char	*key_word;

	i = 1;
	while (i < dict->size)
	{
		key_num = dict->dict_list[i].number;
		key_word = dict->dict_list[i].word;
		
		j = i - 1;
		while (j >= 0 && ft_str_num_cmp(dict->dict_list[j].number, key_num) > 0)
		{
			dict->dict_list[j + 1].number = dict->dict_list[j].number;
			dict->dict_list[j + 1].word = dict->dict_list[j].word;
			j = j - 1;
		}
		dict->dict_list[j + 1].number = key_num;
		dict->dict_list[j + 1].word = key_word;
		i += 1;
	}
	return 0;
}