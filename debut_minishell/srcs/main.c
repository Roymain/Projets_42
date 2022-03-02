/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcuminal <rcuminal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 22:44:20 by rcuminal          #+#    #+#             */
/*   Updated: 2022/03/02 01:53:39 by rcuminal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_printoneenv(t_env *env, char *var)
{
	while (ft_strncmp(env->list->key, var, 7) != 0)
	{
		env->list = env->list->next;
	}
	printf("%s", env->list->content);
}

int	ft_compare(char *prev, char *next)
{
	int	i;

	i = 0;
	while (prev[i] && next[i])
	{
		if (prev[i] < next[i])
			return (1);
		if (prev[i] > next[i])
			return (-1);
		i++;
	}
	if (!prev[i])
		return (1);
	return (-1);
}

int	ft_sorted(t_list *list)
{
	while (list->next)
	{
		if (ft_compare(list->key, list->next->key) == -1)
			return (0);
		list = list->next;
	}
	return (1);
}

void	ft_showexport(t_env *env)
{
	t_list	*tmp;
	t_list	*tmp2;
	int	i;

	i = 0;
	tmp = env->list;
	tmp2 = tmp;
	while (i++ < 10)
	{
		while (tmp)
		{
			if (ft_compare(tmp->key, tmp->next->key) == -1)
			{
				tmp->next = tmp2;
				tmp = tmp->next;
			}
		}
	}
	while (tmp2)
	{
			dprintf(2, "%s   ", tmp2->key);
			dprintf(2, "%s", tmp2->content);
			dprintf(2, "\n");
		tmp2 = tmp2->next;
	}
	return ;
}

void	ft_export(t_env *env, char *export)
{
	t_list	*tmp;

	tmp = ft_lstnew(ft_strndup(export, ft_strichr(export, '=')),
			ft_strnndup(export, ft_strichr(export, '\0'),
				ft_strichr(export, '=') + 1));
	ft_lstadd_back(&env->list, tmp);
	return ;
}

void	ft_showenv(t_env *env)
{
	while (env->list)
	{
		if (env->list->content)
		{
			dprintf(2, "%s   ", env->list->key);
			dprintf(2, "%s", env->list->content);
			dprintf(2, "\n");
		}
		env->list = env->list->next;
	}
}

void	ft_parsenv(t_list **list, char **ev)
{
	int		i;
	t_list	*tmp;

	i = 0;
	while (ev[i])
	{
		tmp = ft_lstnew(ft_strndup(ev[i], ft_strichr(ev[i], '=')),
				ft_strnndup(ev[i], ft_strichr(ev[i], '\0'),
					ft_strichr(ev[i], '=') + 1));
		ft_lstadd_back(list, tmp);
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char **ev)
{
	t_env	*env;
	t_track	*tracker;
	char	*line;
	char	path[4096];


	tracker = ft_memalloc(sizeof(t_track));
	env = ft_track(ft_memalloc(sizeof(t_env)), &tracker);
	ft_parsenv(&env->list, ev);
	while (1)
	{
		line = readline("minishell ~ ");
		builtin_unset(env, "OLDPWD");

//		ft_printoneenv(env, "OLDPWD");			//renvoie pointeur vers le repertoire (NULL (0x0) si ca echoue)
		free(line);
	}
	ft_track_free_all(&tracker);
	return (0);
}
