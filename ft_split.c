/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdiez-ga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 15:52:05 by sdiez-ga          #+#    #+#             */
/*   Updated: 2021/09/20 16:53:44 by sdiez-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *s, char c);
static char		**free_matrix(char **mat, size_t last_index);
static char		**ft_empty_matrix(void);
static char		**ft_make_matrix(const char *s, char c, size_t wc);

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	flag;

	i = 0;
	count = 0;
	flag = 0;
	while (s[i])
	{
		if (flag == 0 && s[i] != c)
		{
			flag = 1;
			count++;
		}
		else if (flag == 1 && s[i] == c)
			flag = 0;
		i++;
	}
	return (count);
}

char	**free_matrix(char **mat, size_t last_index)
{
	while (last_index >= 0)
	{
		if (mat[last_index])
			free(mat[last_index]);
		last_index--;
	}
	free(mat);
	return (0);
}

char	**ft_empty_matrix(void)
{
	char	**mat;

	mat = (char **) ft_calloc(1, sizeof(char *));
	if (!mat)
		return (0);
	return (mat);
}

char	**ft_make_matrix(const char *s, char c, size_t wc)
{
	char	**mat;
	size_t	i;
	size_t	j;

	if (!*s)
		return (ft_empty_matrix());
	mat = ft_calloc(wc + 1, sizeof(char *));
	if (!mat)
		return (0);
	i = 0;
	j = 0;
	while (i < wc && s[j])
	{
		while (*s == c)
			s++;
		j = 0;
		while (s[j] && s[j] != c)
			j++;
		mat[i] = ft_substr(s, 0, j);
		if (!mat[i])
			return (free_matrix(mat, i));
		s += j;
		i++;
	}
	return (mat);
}

char	**ft_split(const char *s, char c)
{
	if (!s)
		return (0);
	return (ft_make_matrix(s, c, ft_count_words(s, c)));
}
