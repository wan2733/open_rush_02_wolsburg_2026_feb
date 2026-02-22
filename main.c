#include "rush02.h"

int parse_num_str(char **num_str, int *is_neg)
{
	char	*new_str = skip_spaces(*num_str);
	*num_str = new_str;
	int i = 0;
	if (new_str[i] == '-')
	{
		*is_neg = 1;
		new_str = ft_strdup(new_str + 1);
		free(*num_str);
		*num_str = new_str;
	}
	else
		*is_neg = 0;
	while (new_str[i])
	{
		if (new_str[i] < '0' || new_str[i] > '9')
			return -1;
		i++;
	}
	return 0;
}

int	main_next(char *dict_file_name, char *num_str)
{
	t_dict	td;
	td.dict_list = malloc(sizeof(t_dict_list) * 100);
	td.size = 0;

	//printf("[info] main_next dict_file_name: %s num_str: %s\n", dict_file_name, num_str);
	int is_neg;
	if (parse_num_str(&num_str, &is_neg))
		return -1;
	parse_dict(dict_file_name, &td);
	char **result;
	char *r = malloc(1);
	if (!r) 
		return -1;
	r[0] = 0;
	result = &r;
	run(num_str, &td, result);
	if (is_neg)
		write(1, "-", 1);
	//write(1, r, ft_strlen(r));
	//printf("Final result: %s\n", r);
	english_post_process(result);
	free(r);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		if (ft_strcmp(argv[1], "-") == 0)
		{
			interactive();
		}
		else
		{
			return (main_next("numbers.dict", argv[1]));
		}
	}
	else if (argc == 3)
	{
		return (main_next(argv[1], argv[2]));
	}
	else
	{
		write(1, "Error: Invalid number of arguments.\n", 36);
		return (1);
	}
	return (0);
}
