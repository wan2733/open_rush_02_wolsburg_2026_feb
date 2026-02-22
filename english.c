#include "rush02.h"
/*
english_post_process post process is for completing the bonus
Using “-”, “,”, “and” to be closer to the correct written syntax

this input char **str is for example 
one hundred twenty three million four hundred fifty six thousand seven hundred eighty nine
after the function finish, char **str is going to be
one hundred twenty three million, four hundred fifty six thousand, seven hundred eighty and nine

this program will return 0 for sucess, -1 for any error

this program will be called in main.c main_next function
*/

int	check_word(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 2] == 't' && str[len - 1] == 'y') // ...ty
		return (1);
	else if (str[len - 2] == 'e' && str[len - 1] == 'd') // hundred
		return (1);
	else if (str[len - 2] == 'n' && str[len - 1] == 'd') // thousand
		return (1);
	else if (str[len - 2] == 'o' && str[len - 1] == 'n') // ...ion
		return (1);
	return (0);
}

int	english_post_process(char **str)
{
	char	**words;
	int	i;
	int	n;
	
	words = ft_split(str[0], " ");
	n = 0;
	while (words[n])
	{
		n++;
	}
	i = 0;
	while (words[i])
	{
		ft_putstr(words[i]);
		write(1, " ", 1);
		if (check_word(words[i]))
		{
			if (i == n - 2)
				ft_putstr("and ");
			else
				ft_putstr(", ");
		}
		i++;
	}
	return 0;
}
