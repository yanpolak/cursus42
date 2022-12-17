/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymarival <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 21:49:01 by ymarival          #+#    #+#             */
/*   Updated: 2022/11/08 00:53:21 by ymarival         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <stdlib.h>

static int	ft_count_words(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == c || s[0] == '\0')
		count--;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c && s[i + 1] != '\0')
			count++;
		i++;
	}
	return (count + 1);
}

static int	ft_strlen_c(const char	*s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*ft_free_all(char **res, int i)
{
	while (i--)
		free(res[i]);
	free(res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		countwords;

	if (!s)
		return (NULL);
	i = 0;
	countwords = ft_count_words(s, c);
	res = malloc(sizeof(char *) * (countwords + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (i < countwords)
	{
		while (*s == c && *s)
			s++;
		res[i] = ft_substr(s, 0, ft_strlen_c(s, c));
		if (res[i] == NULL)
			return (ft_free_all(res, i));
		s += ft_strlen_c(s, c);
		i++;
	}
	res[i] = NULL;
	return (res);
}
