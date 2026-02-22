#include "rush02.h"

int	main_next(char *dict_file_name, char *num_str)
{
	t_dict	td;
	td.dict_list = malloc(sizeof(t_dict_list) * 100);
	td.size = 0;

	//printf("[info] main_next dict_file_name: %s num_str: %s\n", dict_file_name, num_str);
	parse_dict(dict_file_name, &td);
	char **result;
	char *r = malloc(1);
	if (!r) return 1;
	r[0] = 0;
	result = &r;
	run(num_str, &td, result);
	//english_post_process(result);
	write(1, r, ft_strlen(r));
	//printf("Final result: %s\n", r);
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
