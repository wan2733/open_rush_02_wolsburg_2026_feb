/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wchu <wchu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/05 14:06:19 by wchu              #+#    #+#             */
/*   Updated: 2026/02/21 12:40:48 by wchu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (++i < n && src[i])
		dest[i] = src[i];
	while (i < n)
		dest[i++] = 0;
	return (dest);
}

// #include <stdio.h>
// int main()
// {
// 	char d[100];
// 	ft_strncpy(d, "test", 2);
// 	//write(1, d, 5);
// 	printf("%s", d);
// }
