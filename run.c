#include "rush02.h"

int find_in_dict(t_dict *dict, char *num_str, int *index)
{
    int i;

    i = dict->size - 1;
    while (i >= 0)
    {
        if (ft_str_num_cmp(dict->dict_list[i].number, num_str) <= 0) 
        {
            *index = i;
            return 0;
        }
        i--;
    }
    return -1;
}

int run(char *num, t_dict *dict, char **result)
{
    int index;
    char *quotient;
    char *remainder;
    char *suffix;
    char *prefix;
//    char *pre;
    char *new_result;

    prefix = malloc(1);
    if (!prefix) return 1;
    prefix[0] = 0;
    suffix = malloc(1);
    if (!suffix) return 1;
    suffix[0] = 0;

    //printf("num %s %d\n", num, dict->size);
    if (find_in_dict(dict, num, &index))
        return -1;
    if (ft_strcmp(num, "0") == 0 || ft_strcmp(num, "1") == 0)
    {
        //printf("ck1 %s\n", dict->dict_list[index].word);
        new_result = str_dup_malloc(*result, "", dict->dict_list[index].word);
        free(*result);
        
        return 0;
    }
    divide_big_ints(num, dict->dict_list[index].number, &quotient, &remainder);
    //printf("%s %s: %s\n", num, dict->dict_list[index].number, dict->dict_list[index].word);
    //printf("quotient: %s, remainder: %s\n", quotient, remainder);
    *result = str_dup_malloc(*result, "", dict->dict_list[index].word);
    if (remainder[0] != '0')
    {
        if (!run(remainder, dict, &suffix))
        {
            new_result = str_dup_malloc(*result, " ", suffix);
            free(suffix);
            free(*result);
            *result = new_result;
        }
    }
    if (ft_strlen(num) > 2 && quotient && ft_strcmp(quotient, "0") != 0)
    {
        if (!run(quotient, dict, &prefix))
        {
            new_result = str_dup_malloc(prefix, " ", *result);
            free(prefix);
            free(*result);
            *result = new_result;
        }
    }
    free(quotient);
    free(remainder);
    return 0;
}
