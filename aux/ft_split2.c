/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dicarval <dicarval@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 11:05:15 by dicarval          #+#    #+#             */
/*   Updated: 2025/04/15 15:41:12 by dicarval         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_string(char c, char spltr1, char spltr2)
{
	if (spltr1 == c || spltr2 == c)
		return (0);
	return (1);
}

static int	ft_strlen_s(char const *str, char spltr1, char spltr2)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && in_string(str[i], spltr1, spltr2))
		i++;
	return (i);
}

static int	count_strings(char const *str, char spltr1, char spltr2)
{
	int	i;
	int	counter;

	counter = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && !in_string(str[i], spltr1, spltr2))
			i++;
		if (str[i] != '\0')
			counter++;
		while (str[i] != '\0' && in_string(str[i], spltr1, spltr2))
			i++;
	}
	return (counter);
}

static char	*word_allocate(char const *str, char spltr1, char spltr2)
{
	int		len_word;
	char	*word;
	int		i;

	i = 0;
	len_word = ft_strlen_s(str, spltr1, spltr2);
	word = (char *)malloc((len_word + 1) * sizeof(char));
	if (word == NULL)
		return (NULL);
	word[len_word] = 0;
	while (str[i] != '\0' && in_string(str[i], spltr1, spltr2))
	{
		word[i] = str[i];
		i++;
	}
	return (word);
}
//line 58 - length of the string
//line 59 - malloc of length of the string

char	**ft_split2(char const *str, char spltr1, char spltr2)
{
	char	**list_str;
	int		number_str;
	int		g;

	g = 0;
	if (str == NULL)
		return (NULL);
	number_str = count_strings(str, spltr1, spltr2);
	list_str = (char **)malloc((number_str + 1) * sizeof(char *));
	if (list_str == NULL)
		return (NULL);
	list_str[number_str] = 0;
	while (*str != '\0')
	{
		while (*str != '\0' && !in_string(*str, spltr1, spltr2))
			str++;
		if (*str != '\0')
		{
			list_str[g] = word_allocate(str, spltr1, spltr2);
			g++;
		}
		while (*str != '\0' && in_string(*str, spltr1, spltr2))
			str++;
	}
	return (list_str);
}
//line 80 - count the number of strings
//line 81 - malloc the array of strings
//line 87 - moves forward until it finds a non-splitter
//line 91 - allocates the string in the correct order
//line 94 - moves forward until it finds a splitter or the end of the string
