/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shteng <shteng@student.42wolfsburg.de      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/18 12:39:46 by shteng            #+#    #+#             */
/*   Updated: 2026/02/22 18:04:03 by shteng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "rush02.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	len;

	if (ft_strlen(s1) >= ft_strlen(s2))
	{
		len = ft_strlen(s1);
	}
	else
	{
		len = ft_strlen(s2);
	}
	i = 0;
	while (i < len)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_str_num_cmp(char *s1, char *s2)
{
	int	s1_len;
	int	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if (s1_len > s2_len)
		return (1);
	else if (s1_len < s2_len)
		return (-1);
	else
		return (ft_strcmp(s1, s2));
}

/*
#include <stdio.h>
#include <string.h>
int	main(int argc, char **argv)
{
	char	*s1;
	char	*s2;

	if (argc == 3)
	{
		s1 = argv[1];
		s2 = argv[2];
		printf("#%s, %s\n", s1, s2);
		printf("%d, %d\n", strcmp(s1, s2), ft_strcmp(s1, s2));
	}
}
*/
