/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntesfu <ntesfu@student.42abudhabi.ae>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:39:11 by ntesfu            #+#    #+#             */
/*   Updated: 2022/01/27 18:09:03 by ntesfu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	getwordcount(const char *str, char charset)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (str[i])
	{
		if (str[i] != charset && word == 0)
		{
			count++;
			word = 1;
		}
		else if (str[i] == charset && word == 1)
			word = 0;
		i++;
	}
	return (count);
}

static void	getword(const char *str, int *pos, int charcount, char *befld)
{
	int		i;

	i = 0;
	while (i < charcount)
	{
		befld[i] = str[*pos];
		i++;
		*pos = *pos + 1;
	}
	befld[i] = '\0';
}

static char	**split(const char *str, char charset, int wordlen, char **splitted)
{
	int		i;
	int		j;
	int		arr;

	i = 0;
	arr = 0;
	while (arr < wordlen && str[i])
	{
		j = 0;
		while (str[i] && str[i] == charset)
			i++;
		while (str[i] && str[i] != charset)
		{	
			i++;
			j++;
		}
		splitted[arr] = (char *)malloc(sizeof (char) * (j + 1));
		if (splitted[arr] == NULL)
			return (NULL);
		i -= j;
		getword(str, &i, j, splitted[arr]);
		arr++;
	}
	splitted[wordlen] = NULL;
	return (splitted);
}

char	**ft_split(char const *s, char c)
{
	int		wordlen;
	char	**splitted;

	wordlen = getwordcount(s, c);
	splitted = (char **)malloc(sizeof (char *) * (wordlen + 1));
	if (splitted == NULL)
		return (NULL);
	return (split(s, c, wordlen, splitted));
}
