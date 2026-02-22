#include "rush02.h"
#include <stdio.h>
#include <stdlib.h>

// Helper: find word in t_dict for a given number
char *find_word(long long num, t_dict *td)
{
    unsigned int i;

    i = 0;
    while (i < td->size)
    {
        if (*(td->dict_list[i].number) == num)
            return (td->dict_list[i].word);
        i++;
    }
    return (NULL);
}

// Recursive function to print number
int num_to_lang(long long num, char *lang, t_dict *td)
{
    long long scales[4];
    int i;
    char *scale_word;
    char *tens_word;
    char *unit_word;
    long long tens;

    (void)lang;

    if (num == 0)
    {
        ft_putstr(find_word(0, td));
        return (0);
    }

    if (num < 0)
    {
        ft_putstr("Minus ");
        num = -num;
    }

    scales[0] = 1000000000LL;
    scales[1] = 1000000LL;
    scales[2] = 1000LL;
    scales[3] = 100LL;

    i = 0;
    while (i < 4)
    {
        if (num >= scales[i])
        {
            num_to_lang(num / scales[i], lang, td);
            ft_putstr(" ");
            scale_word = find_word(scales[i], td);
            if (scale_word)
            {
                ft_putstr(scale_word);
                ft_putstr(" ");
            }
            num = num % scales[i];
        }
        i++;
    }

    if (num >= 20)
    {
        tens = (num / 10) * 10;
        tens_word = find_word(tens, td);
        if (tens_word)
        {
            ft_putstr(tens_word);
            ft_putstr(" ");
        }
        num = num % 10;
    }

    if (num > 0)
    {
        unit_word = find_word(num, td);
        if (unit_word)
            ft_putstr(unit_word);
        ft_putstr(" ");
    }

    return (0);
}