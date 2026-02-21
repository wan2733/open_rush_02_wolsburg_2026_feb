#include "rush02.h"
#include <stdio.h>
#include <stdlib.h>

// Helper: find word in t_dict for a given number
char *find_word(long long num, t_dict *td)
{
    for (unsigned int i = 0; i < td->size; i++)
    {
        if (*(td->dict_list[i].number) == num)
            return td->dict_list[i].word;
    }
    return NULL;
}

// Recursive function to print number
int num_to_lang(long long num, char *lang, t_dict *td)
{
    if (num == 0)
    {
        ft_putstr(find_word(0, td));
        return 0;
    }

    // handle negative numbers
    if (num < 0)
    {
        ft_putstr("Minus ");
        num = -num;
    }

    // Handle billions, millions, thousands
    long long scales[] = {1000000000LL, 1000000LL, 1000LL, 100LL};
    for (int i = 0; i < 4; i++)
    {
        if (num >= scales[i])
        {
            long long left = num / scales[i];
            num_to_lang(left, lang, td); // recursive call for left part
            ft_putstr(" ");
            char *scale_word = find_word(scales[i], td);
            if (scale_word)
            {
                ft_putstr(scale_word);
                ft_putstr(" ");
            }
            num %= scales[i]; // remaining part
        }
    }

    // Handle tens and units
    if (num >= 20)
    {
        long long tens = (num / 10) * 10;
        char *tens_word = find_word(tens, td);
        if (tens_word)
        {
            ft_putstr(tens_word);
            ft_putstr(" ");
        }
        num %= 10;
    }

    if (num > 0)
    {
        char *unit_word = find_word(num, td);
        if (unit_word)
            ft_putstr(unit_word);
        ft_putstr(" ");
    }

    return 0;
}