/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mathmart <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:55:01 by mathmart          #+#    #+#             */
/*   Updated: 2022/05/23 19:24:22 by mathmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	ft_size(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	return (i + j);
}

char	*mini_strjoin(char *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dest;

	dest = (char *)malloc(sizeof(char) * ft_size(s1, s2) + 1);
	if (!dest)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dest[++j] = s1[i];
	i = -1;
	while (s2[++i])
		dest[++j] = s2[i];
	dest[++j] = '\0';
	return (dest);
}
