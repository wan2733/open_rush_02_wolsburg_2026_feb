#include "rush02.h"

int	is_greater_equal(char *s1, char *s2)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (len1 > len2)
		return (1);
	if (len1 < len2)
		return (0);
	return (ft_strcmp(s1, s2) >= 0);
}

void	subtract_strings(char *s1, char *s2)
{
	int	i;
	int	j;
	int	borrow;
	int	val1;
	int	val2;
	int	leading;
	int	diff;

	i = ft_strlen(s1) - 1;
	j = ft_strlen(s2) - 1;
	borrow = 0;
	while (i >= 0)
	{
		val1 = s1[i] - '0';
		if (j >= 0) 
			val2 = s2[j] - '0';
		else
			val2 = 0;
		diff = val1 - val2 - borrow;

		if (diff < 0)
		{
			diff += 10;
			borrow = 1;
		}
		else
		{
			borrow = 0;
		}
		s1[i--] = diff + '0';
		j--;
	}
	leading = 0;
	while (s1[leading] == '0' && s1[leading + 1] != '\0')
		leading++;
	if (leading > 0)
		ft_strncpy(s1, s1 + leading, ft_strlen(s1) - leading + 1);
}

int	divide_big_ints(char *dividend, char *divisor, char **quotient, char **remainder)
{
	int		n;
	char	*q_buf;
	char	*current;
	int		q_idx;
	int		i;
	int		curr_len;
	int		count;

	if (ft_strcmp(divisor, "0") == 0)
		return (1);

	n = ft_strlen(dividend);
	*q_buf = malloc(n + 1);
	*current = calloc(n + 2, sizeof(char));
	if (!q_buf || !current)
	{
		free(q_buf);
		free(current);
		return (1);
	}

	q_idx = 0;
	i = 0;
	while (i < n)
	{
		curr_len = ft_strlen(current);
		current[curr_len] = dividend[i];
		current[curr_len + 1] = '\0';

		while (current[0] == '0' && current[1] != '\0') 
			ft_strncpy(current, current + 1, strlen(current));

		count = 0;
		while (is_greater_equal(current, divisor)) 
		{
			subtract_strings(current, divisor);
			count++;
		}
		q_buf[q_idx++] = count + '0';
		i++;
	}
	q_buf[q_idx] = '\0';

	char *q_start = q_buf;
	while (*q_start == '0' && *(q_start + 1) != '\0') 
		q_start++;
	
	*quotient = ft_strdup(q_start);
	*remainder = ft_strdup(current);

	free(q_buf);
	free(current);

	if (!*quotient || !*remainder) 
		return 1;
	return 0;
}
