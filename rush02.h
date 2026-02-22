/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/22 21:56:49 by wchu              #+#    #+#             */
/*   Updated: 2026/02/22 22:09:43 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_dict
{
	unsigned int		size;
	struct s_dict_list	*dict_list;
}						t_dict;

typedef struct s_dict_list
{
	char				*number;
	char				*word;
}						t_dict_list;

int						main_next(char *dict_file_name, char *num_str);
int						ft_strlen(char *str);
char					*str_dup_malloc(char *s1, char *sep, char *s2);
char					*ft_strncpy(char *dest, char *src, unsigned int n);
char					**ft_split(char *str, char *charset);
int						parse_dict(char *filename, t_dict *tdp);
int						parse_list_row(char *list_row, t_dict_list *tdlp);
int						parse_dict_str(char *str, int size, t_dict *tdp);
int						parse_dict(char *filename, t_dict *tdp);
int						free_dict(t_dict *tdp);
int						ft_strcmp(char *s1, char *s2);
int						ft_str_num_cmp(char *s1, char *s2);
void					interactive(void);
int						ft_atoi(char *str, long long *value);
char					*ft_strdup(char *str);
void					free_str_split(char **strs);
int						run(char *num, t_dict *dict, char **result);
int						divide_big_ints(char *dividend, char *divisor,
							char **quotient, char **remainder);
char					*skip_spaces(char *list_row);
int						ft_split_free(char **splited_str);
int						sort_dict(t_dict *dict);
void					print_dict(t_dict *tdp);
char					*skip_spaces_num(char *list_row);
int						print_error(int error_code);
void					ft_putstr(char *str);
int						english_post_process(char **str);
void					ss_helper(int i, int j, char *s1, char *s2);
int						is_greater_equal(char *s1, char *s2);
void					subtract_strings(char *s1, char *s2);
int						main_next(char *dict_file_name, char *num_str);
int						parse_num_str(char **num_str);
int						print_error(int error_code);
#endif
