/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jamerlin <jamerlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 09:10:23 by jamerlin          #+#    #+#             */
/*   Updated: 2017/10/12 13:55:12 by jamerlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	**ft_sort_tab(char **tab)
{
	int		i;
	char	*buff;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_strcmp(tab[i], tab[i + 1]) > 0)
		{
			buff = ft_strdup(tab[i]);
			ft_memdel((void **)&tab[i]);
			tab[i] = ft_strdup(tab[i + 1]);
			ft_memdel((void **)&tab[i + 1]);
			tab[i + 1] = ft_strdup(buff);
			ft_memdel((void **)&buff);
		}
		i++;
	}
	if (ft_check_tab(tab) > 0)
		return (ft_sort_tab(tab));
	tab[i + 1] = NULL;
	return (tab);
}

char	**ft_sort_tab_time(char **tab)
{
	int			i;
	char		*buff;
	t_sstat		filestat;
	long		date_1;

	i = -1;
	while (tab[++i] && tab[i + 1])
	{
		lstat(tab[i], &filestat);
		date_1 = filestat.st_mtime;
		lstat(tab[i + 1], &filestat);
		if (date_1 < filestat.st_mtime)
		{
			buff = ft_strdup(tab[i]);
			ft_memdel((void **)&tab[i]);
			tab[i] = ft_strdup(tab[i + 1]);
			ft_memdel((void **)&tab[i + 1]);
			tab[i + 1] = ft_strdup(buff);
			ft_memdel((void **)&buff);
		}
	}
	if (ft_check_tab_time(tab) > 0)
		return (ft_sort_tab_time(tab));
	tab[i + 1] = NULL;
	return (tab);
}

char	**ft_sort_type(char **tab)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (tab[i] && tab[i + 1])
	{
		if (ft_isdir(tab[i]) > 0)
		{
			j = i;
			while (tab[j] && ft_isdir(tab[j]) > 0)
				j++;
			if (tab[j] != NULL)
			{
				buff = ft_strdup(tab[i]);
				ft_memdel((void **)&tab[i]);
				tab[i] = ft_strdup(tab[j]);
				ft_memdel((void **)&tab[j]);
				tab[j] = ft_strdup(buff);
				ft_memdel((void **)&buff);
			}
		}
		i++;
	}
	return (tab);
}

t_arg	*sort_tab(t_arg *list)
{
	t_arg	*tmp;
	int		i;

	i = 0;
	tmp = list;
	if (tmp->arg != NULL)
	{
		tmp->arg = ft_sort_tab(tmp->arg);
		if (tmp->arg_t)
			tmp->arg = ft_sort_tab_time(tmp->arg);
		if (tmp->arg_rmin)
			tmp->arg = reverse_tab(tmp->arg);
	}
	if (tmp->file != NULL)
	{
		tmp->file = ft_sort_tab(tmp->file);
		if (tmp->arg_t)
			tmp->file = ft_sort_tab_time(tmp->file);
		if (tmp->arg_rmin)
			tmp->file = reverse_tab(tmp->file);
	}
	return (list);
}

char	**reverse_tab(char **tab)
{
	int		i;
	int		j;
	int		k;
	char	*buff;

	i = 0;
	j = 0;
	if (!tab)
		return (NULL);
	k = len_tab(tab);
	j = k - 1;
	while (i < j)
	{
		buff = ft_strdup(tab[i]);
		ft_memdel((void **)&tab[i]);
		tab[i] = ft_strdup(tab[j]);
		ft_memdel((void **)&tab[j]);
		tab[j] = ft_strdup(buff);
		ft_memdel((void **)&buff);
		i++;
		j--;
	}
	tab[k] = NULL;
	return (tab);
}
