#include "rush02.h"


int main_next(char *dict_file_name, char *num_str)
{
    printf("[info] main_next dict_file_name: %s num_str: %s", dict_file_name, num_str);
	t_dict td;
	parse_dict(dict_file_name, &td);
	return (0);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
	if (ft_strcmp(argv[1], "-") == 0)
    	{
		printf("Placeholder for interactive mode\n");
    	}
   	else
    	{
		return main_next("numbers.dict", argv[1]);
    	}
    }
    else if (argc == 3)
    {
        return main_next(argv[1], argv[2]);
    }
    else
    {
        write(1, "Error: Invalid number of arguments.\n", 36);
        return (1);
    }
    return (0);
}
