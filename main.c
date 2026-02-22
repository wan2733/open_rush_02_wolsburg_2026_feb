#include "rush02.h"

int print_error(int error_code)
{
	if (error_code == 0)
		return -1;
	if (error_code < -1)
		write(1, "Dict Error\n", 11);
	else
		write(1, "Error\n", 6);
	return 0;
}

int parse_num_str(char **num_str)
{
	char	*new_str = skip_spaces_num(*num_str);
	*num_str = new_str;
	int i = 0;
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

	if (parse_num_str(&num_str))
		return -1;
	if (parse_dict(dict_file_name, &td))
		return -2;
	sort_dict(&td);
	char **result;
	char *r = malloc(1);
	if (!r) 
		return -1;
	r[0] = 0;
	result = &r;
	run(num_str, &td, result);
	english_post_process(result);
	free(r);
	free_dict(&td);
	free(num_str);
	return (0);
}

int	main(int argc, char **argv)
{
	int	ec;

	if (argc == 2)
	{
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
