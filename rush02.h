#ifndef RUSH02_H
# define RUSH02_H
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

typedef struct s_dict
{
    unsigned int	size;
    struct s_dict_list		*dict_list;
}				t_dict;

typedef struct s_dict_list
{
    long long	*number;
    char		*word;
}				t_dict_list;

char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	**ft_split(char *str, char *charset);
int	parse_dict(char *filename, t_dict *tdp);
int	parse_list_row(char *list_row, t_dict_list *tdlp);
int	parse_dict_str(char *str, int size, t_dict *tdp);
int	parse_dict(char *filename, t_dict *tdp);
int	free_dict(t_dict tdp);
int	ft_strcmp(char *s1, char *s2);
void	interactive(void);

#endif
