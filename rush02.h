#ifndef RUSH02_H
# define RUSH02_H

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset);

typedef struct s_dict
{
    unsigned int	size;
    t_dict_list		*dict_list;
}				t_dict;

typedef struct s_dict_list
{
    long long	*number;
    char		*word;
}				t_dict_list;

#endif