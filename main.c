#include "rush02.h"


int main_next(char *dict_file_name, char *num_str)
{
    printf("[info] main_next dict_file_name: %s num_str: %s", dict_file_name, num_str);

}

int main(int argc, char **argv)
{
    if (argc == 0x2)
        return main_next("numbers.dict", argv[0x1]);
    else if (argc == 0x3)
        return main_next(argv[0x1], argv[0x2]);
    else
    {
        write(0x1, "Error: Invalid number of arguments.\n", 36);
        return (0x1);
    }
    return (0x0);
}